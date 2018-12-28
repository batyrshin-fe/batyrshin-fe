// work_4_1.cpp: главный файл проекта.

#include "stdafx.h"
#include "Form1.h"
#define _USE_MATH_DEFINES
#include <cmath>


using namespace work_4_1;

// Константы
const int a11=66;
const int a12=129;
const int a13=25;
const int a21=-38;
const int a22=-74;
const int a23=112;
const int a31=112;
const int a32=-94;
const int a33=-18;
const int b11=75;
const int b12=0;
const int b13=103;
const int b21=75;
const int b22=-25;
const int b23=-52;
const int b31=75;
const int b32=130;
const int b33=0;
const int size_m=8;
typedef double m8x8[size_m][size_m];

m8x8 A,AT,a1,a0,tst;

[STAThreadAttribute]


int main(array<System::String ^> ^args)
{
	// Включение визуальных эффектов Windows до создания каких-либо элементов управления
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Создание главного окна и его запуск
	Application::Run(gcnew Form1());
	
	return 0;
}


double roundResult (double d, int p){ // округление
   int pr=1;
   for (int j=0; j<p; j++)
     pr*=10;
   d = d*pr;
   int i = (int) d;
   return (double) i/pr;
  }

Void ColorMessage(System::Drawing::Color  _c){ //разложение цвета на каналы
	MessageBox::Show( "RGB=("+System::Convert::ToString(_c.R)+", "
		+System::Convert::ToString(_c.G)+", "
		+System::Convert::ToString(_c.B)+")","Сообщение о цвете" );	
}

Void MatrMessage(m8x8 matr){//позволяет просмотреть матрицу
	System::String ^str="";
	for(int i=0;i<size_m;i++){
		for(int j=0;j<size_m;j++){
			str+=System::Convert::ToString(roundResult(matr[i][j],4));
			if(matr[i][j]<0) str+="     ";
			else str+="      ";
		}
		str+="\r\n";
	}
	MessageBox::Show( str,"Матрица 8х8" );	
}


Void MultiMatrix(m8x8 m1,m8x8 m2, m8x8 res){//перемножение матриц
	for(int i=0;i<size_m;i++)
		for(int j=0;j<size_m;j++){
			res[i][j]=(double)0;
			for(int k=0;k<size_m;k++)
				res[i][j]+=m1[i][k]*m2[k][j];
		}
}

Void TransponMatrix(m8x8 m1, m8x8 res){//транспонирование матриц
	for(int i=0;i<size_m;i++)
		for(int j=0;j<size_m;j++)	res[i][j]=m1[j][i];			
}




Void FDCT_8x8(m8x8 m1, m8x8 res){	//прямое преобразование		
	MultiMatrix(A,m1,a1);
	MultiMatrix(a1,AT,res);
}



Void IDCT_8x8(m8x8 m1, m8x8 res){ //обратное преобразование	
	MultiMatrix(AT,m1,a1);
	MultiMatrix(a1,A,res);
}

double C_(int ij, int N){	//коэф-функция из преобразования
	if(ij==0) return sqrt(1.0/N);
	else return sqrt(2.0/N);
}

Void myTest(void){
tst[0][0]=5;	tst[0][1]=11;	tst[0][2]=8;	tst[0][3]=10;	
tst[1][0]=9;	tst[1][1]=8;	tst[1][2]=4;	tst[1][3]=12;
tst[2][0]=1;	tst[2][1]=10;	tst[2][2]=11;	tst[2][3]=4;
tst[3][0]=19;	tst[3][1]=6;	tst[3][2]=15;	tst[3][3]=7;
MatrMessage(tst);

m8x8 tmp,tst1;

FDCT_8x8(tst,tmp);
MatrMessage(tmp);

IDCT_8x8(tmp,tst1);
MatrMessage(tst1);
}

Void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e) { 
	
	//размеры изображений делаю одинаковы	
	Wpic=pictureBox1->Width;	Hpic=pictureBox1->Height;
	pictureBox2->Width=Wpic;	pictureBox2->Height=Hpic;

	butClear_Click( sender, e);//очистка рисунков 
	//создание матрицы преобразований
	for(int i=0;i<size_m;i++)
		for(int j=0;j<size_m;j++)
			A[i][j]=C_(i, size_m) * cos((2 * j + 1) * i * M_PI / 2 / size_m);	

	//транспонирование матрицы преобразований
	TransponMatrix(A,AT);														
	//формирование фильтра
	this->saveFileDialog1->Filter="BMP files|*.bmp|JPG files|*.jpg|PNG files|*.png|GIF files|*.gif|TIFF files|*.tiff|EMF files|*.emf|WMF files|*.wmf|EXIF files|*.exif|Все файлы|*.*";
	this->openFileDialog1->Filter=this->saveFileDialog1->Filter;
	this->openFileDialog1->FilterIndex=9;	
}


Void Form1::PrepareData(void){	//подготовка расчетных данных (переменных формы)
		
	NN=(int)(Wpic*Hpic);//размерность для массивов 	
	
	delete[] R1;//освобождение памяти предыдущих массивов  
	delete[] G1;
	delete[] B1;
	delete[] Y1;
	delete[] Y2;
	delete[] Y9;
	delete[] U;
	delete[] V;
	delete[] R2; 
	delete[] G2;
	delete[] B2;

	R1=new int[NN];	//динамическое выделение памяти под массивы
	G1=new int[NN];
	B1=new int[NN];
	Y1=new int[NN];
	Y2=new int[NN];
	Y9=new int[NN];
	U=new int[NN];
	V=new int[NN];
	R2=new int[NN];	
	G2=new int[NN];
	B2=new int[NN];	
	
}


Void Form1::FirstYUV(void){	//преобразование при загрузке изображеня Y1,U,V
	PrepareData();
	int r,g,b,y,u,v;
	Bitmap ^bmp1= gcnew Bitmap(pictureBox1->BackgroundImage, pictureBox1->Width, pictureBox1->Height);
	//Преобразование
	for(int j=0;j<Hpic;j++)
		for(int i=0;i<Wpic;i++){
		   int n=j*Wpic+i;
			Color clr=bmp1->GetPixel(i,j);

			r=clr.R;
			g=clr.G;
			b=clr.B;

			R1[n]=r;
			G1[n]=g;
			B1[n]=b;			

			//первые преобразования	(целочисленные)		
			Y1[n]=a11*R1[n] + a12*G1[n] + a13*B1[n];
			U[n]=a21*R1[n] + a22*G1[n] + a23*B1[n] + 128*220;
			V[n]=a31*R1[n] + a32*G1[n] + a33*B1[n] + 128*220;
			//для отладки
			y=Y1[n];
			u=U[n];
			v=V[n];		

		}	
}


Void Form1::buttonAbout_Click(System::Object^  sender, System::EventArgs^  e){	

	MessageBox::Show( "Выполнено Батыршином Филиппом для курсовой работы","Сообщение о разработчике Программного средства" );	

}


Void Form1::butLoad_Click(System::Object^  sender, System::EventArgs^  e){	
openFileDialog1->InitialDirectory = System::Windows::Forms::Application::StartupPath+"\\Img";
openFileDialog1->RestoreDirectory = true;

	if (this->openFileDialog1->ShowDialog()==::DialogResult::OK) 
		{ 
				try
				{							
					Bitmap ^bmp1= gcnew Bitmap(openFileDialog1->FileName);					
					pictureBox1->BackgroundImage=bmp1;//помещение нового рисунка на элемент					
					FirstYUV();
				} 
				catch(int)				
				{MessageBox::Show( "Этот файл - не изображение...","Сообщение об ошибке" );	
				}
							
		}//конец if	
}

Void Form1::buttonSave_Click(System::Object^  sender, System::EventArgs^  e){	
saveFileDialog1->InitialDirectory = System::Windows::Forms::Application::StartupPath+"\\Img";
saveFileDialog1->RestoreDirectory = true;

	if (this->saveFileDialog1->ShowDialog()==::DialogResult::OK) 
		{ 			
				try
				{		
					switch(saveFileDialog1->FilterIndex){
						case 1: pictureBox2->BackgroundImage->Save(saveFileDialog1->FileName, System::Drawing::Imaging::ImageFormat::Bmp);//помещение нового рисунка в файл	
								break;
						case 2: pictureBox2->BackgroundImage->Save(saveFileDialog1->FileName, System::Drawing::Imaging::ImageFormat::Jpeg);
								break;
						case 3: pictureBox2->BackgroundImage->Save(saveFileDialog1->FileName, System::Drawing::Imaging::ImageFormat::Png);
								break;
						case 4: pictureBox2->BackgroundImage->Save(saveFileDialog1->FileName, System::Drawing::Imaging::ImageFormat::Gif);
								break;
						case 5: pictureBox2->BackgroundImage->Save(saveFileDialog1->FileName, System::Drawing::Imaging::ImageFormat::Tiff);
								break;
						case 6: pictureBox2->BackgroundImage->Save(saveFileDialog1->FileName, System::Drawing::Imaging::ImageFormat::Emf);
								break;
						case 7: pictureBox2->BackgroundImage->Save(saveFileDialog1->FileName, System::Drawing::Imaging::ImageFormat::Wmf);
								break;
						case 8: pictureBox2->BackgroundImage->Save(saveFileDialog1->FileName, System::Drawing::Imaging::ImageFormat::Exif);
								break;
						default: pictureBox2->BackgroundImage->Save(saveFileDialog1->FileName, System::Drawing::Imaging::ImageFormat::Bmp);//помещение нового рисунка в файл	
								break;						
					}
				} 
				catch(int)				
				{MessageBox::Show( "Ошибка записи файла...","Сообщение об ошибке" );	
				}
				
			MessageBox::Show( "Файл успешно сохранен...","Сообщение" );	
		}//конец if	
}





Void Form1::butClear_Click(System::Object^  sender, System::EventArgs^  e){	

	//установка свойств pictureBox->BackgroundImage для рисунков 
	Bitmap ^bmp1= gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
	for(int i=0;i<Wpic;i++)
		for(int j=0;j<Hpic;j++)	   bmp1->SetPixel(i,j,Color::WhiteSmoke);
	pictureBox1->BackgroundImage=bmp1;
	pictureBox2->BackgroundImage=bmp1;	

}



Void Form1::butFDCT_Click(System::Object^  sender, System::EventArgs^  e){ 	
	m8x8 na,dct;
	//заполняет Y2 коэффициентами от Y1
	for(int h=0;h<Hpic;h+=size_m)
		for(int w=0;w<Wpic;w+=size_m){
			for(int j=0;j<size_m;j++)
					for(int i=0;i<size_m;i++){						//все коэф
						int n=(h+j)*Wpic+(w+i);
						na[i][j]=Y1[n];						
					}
			FDCT_8x8(na,dct);	//преобразования
			for(int j=0;j<size_m;j++)
					for(int i=0;i<size_m;i++){
						int n=(h+j)*Wpic+(w+i);
						Y2[n]=(int)dct[i][j]; 						
					}
		}
	//копирование в массив для отображения
	for(int i=0;i<NN;i++)	Y9[i]=Y2[i];
	ShowResult();
}


//кнопки различного качества восстановления изображения

Void Form1::butIDCT1_Click(System::Object^  sender, System::EventArgs^  e){
	m8x8 na,dct;
	for(int j=0;j<size_m;j++)
		for(int i=0;i<size_m;i++)	dct[i][j]=0;
	//заполняет Y1 преобразуя из Y2	(потеря качества)
	for(int h=0;h<Hpic;h+=size_m)
		for(int w=0;w<Wpic;w+=size_m){			
			int n=h*Wpic+w;
			dct[0][0]=Y2[n];	//читается только 1 коэф из 64						
			IDCT_8x8(dct,na);	//преобразования
			for(int j=0;j<size_m;j++)
					for(int i=0;i<size_m;i++){
						int n=(h+j)*Wpic+(w+i);
						Y1[n]=(int)na[i][j]; //if(Y1[n]<0)Y1[n]=0;if(Y1[n]>255*220)Y1[n]=255*220;						
					}
		}

	//копирование в массив для отображения
	for(int i=0;i<NN;i++)	Y9[i]=Y1[i];
	ShowResult();
}

Void Form1::butIDCT2_Click(System::Object^  sender, System::EventArgs^  e){
	m8x8 na,dct;
	for(int j=0;j<size_m;j++)
		for(int i=0;i<size_m;i++)	dct[i][j]=0;
	//заполняет Y1 преобразуя из Y2	(потеря качества)
	for(int h=0;h<Hpic;h+=size_m)
		for(int w=0;w<Wpic;w+=size_m){
			for(int j=0;j<2;j++)
					for(int i=0;i<2;i++){
						int n=(h+j)*Wpic+(w+i);
						dct[i][j]=Y2[n];						
					}
			IDCT_8x8(dct,na);	//преобразования
			for(int j=0;j<size_m;j++)
					for(int i=0;i<size_m;i++){
						int n=(h+j)*Wpic+(w+i);
						Y1[n]=(int)na[i][j]; //if(Y1[n]<0)Y1[n]=0;if(Y1[n]>255*220)Y1[n]=255*220;						
					}
		}

	//копирование в массив для отображения
	for(int i=0;i<NN;i++)	Y9[i]=Y1[i];
	ShowResult();
}

Void Form1::butIDCT3_Click(System::Object^  sender, System::EventArgs^  e){
	m8x8 na,dct;
	for(int j=0;j<size_m;j++)
		for(int i=0;i<size_m;i++)	dct[i][j]=0;
	//заполняет Y1 преобразуя из Y2	(потеря качества)
	for(int h=0;h<Hpic;h+=size_m)
		for(int w=0;w<Wpic;w+=size_m){
			for(int j=0;j<3;j++)
					for(int i=0;i<3;i++){
						int n=(h+j)*Wpic+(w+i);
						dct[i][j]=Y2[n];						
					}
			IDCT_8x8(dct,na);	//преобразования
			for(int j=0;j<size_m;j++)
					for(int i=0;i<size_m;i++){
						int n=(h+j)*Wpic+(w+i);
						Y1[n]=(int)na[i][j]; //if(Y1[n]<0)Y1[n]=0;if(Y1[n]>255*220)Y1[n]=255*220;						
					}
		}

	//копирование в массив для отображения
	for(int i=0;i<NN;i++)	Y9[i]=Y1[i];
	ShowResult();
}

Void Form1::butIDCT4_Click(System::Object^  sender, System::EventArgs^  e){
	m8x8 na,dct;
	for(int j=0;j<size_m;j++)
		for(int i=0;i<size_m;i++)	dct[i][j]=0;
	//заполняет Y1 преобразуя из Y2	(потеря качества)
	for(int h=0;h<Hpic;h+=size_m)
		for(int w=0;w<Wpic;w+=size_m){
			for(int j=0;j<4;j++)
					for(int i=0;i<4;i++){
						int n=(h+j)*Wpic+(w+i);
						dct[i][j]=Y2[n];						
					}
			IDCT_8x8(dct,na);	//преобразования
			for(int j=0;j<size_m;j++)
					for(int i=0;i<size_m;i++){
						int n=(h+j)*Wpic+(w+i);
						Y1[n]=(int)na[i][j]; //if(Y1[n]<0)Y1[n]=0;if(Y1[n]>255*220)Y1[n]=255*220;						
					}
		}

	//копирование в массив для отображения
	for(int i=0;i<NN;i++)	Y9[i]=Y1[i];
	ShowResult();
}

//кнопка полного восстановления изображения (все коэффициенты использованы)
Void Form1::butIDCT_Click(System::Object^  sender, System::EventArgs^  e){
	m8x8 na,dct;
	//заполняет Y1 преобразуя из Y2	(потеря качества)
	for(int h=0;h<Hpic;h+=size_m)
		for(int w=0;w<Wpic;w+=size_m){
			for(int j=0;j<size_m;j++)
					for(int i=0;i<size_m;i++){
						int n=(h+j)*Wpic+(w+i);
						dct[i][j]=Y2[n];						
					}
			IDCT_8x8(dct,na);	//преобразования
			for(int j=0;j<size_m;j++)
					for(int i=0;i<size_m;i++){
						int n=(h+j)*Wpic+(w+i);
						Y1[n]=(int)na[i][j]; //if(Y1[n]<0)Y1[n]=0;if(Y1[n]>255*220)Y1[n]=255*220;						
					}
		}

	//копирование в массив для отображения
	for(int i=0;i<NN;i++)	Y9[i]=Y1[i];
	ShowResult();
}



Void Form1::ShowResult(){
	int r,g,b,y,u,v;
		
	Bitmap ^bmp2= gcnew Bitmap(pictureBox2->BackgroundImage, pictureBox2->Width, pictureBox2->Height);
	//Преобразование
	
	for(int j=0;j<Hpic;j++)
		for(int i=0;i<Wpic;i++){
		   int n=j*Wpic+i;
		// чтение из массива
			y=Y9[n];
			u=U[n];
			v=V[n];

		//обратные преобразования (целочисленные) с проверкой и ограничениями			
		
				r= (b11*y + b12 * (u-128*220) + b13 * (v-128*220))>>14;
				g= (b21*y + b22 * (u-128*220) + b23 * (v-128*220))>>14;
				b= (b31*y + b32 * (u-128*220) + b33 * (v-128*220))>>14;						

				if(r<0)r=0;	if(r>255)r=255;						
				if(g<0)g=0;	if(g>255)g=255;				
				if(b<0)b=0;	if(b>255)b=255;

			//сохранение в массив
			R2[n]=r;
			G2[n]=g;
			B2[n]=b;
						
			//формирование нового цвета пикселя
			Color ^clr2 = Color::FromArgb( (int)R2[n],(int)G2[n],(int)B2[n] );
			//ColorMessage(*clr2);
			bmp2->SetPixel(i,j,*clr2);			
		}
	   pictureBox2->BackgroundImage=bmp2;//помещение нового рисунка на элемент
	pictureBox2->Refresh();	
	
}