#pragma once

#include "stdafx.h"
#include "MyGUI.h"

#include "MyApp.h"

#include "FrameworkBase\\Header\\GUI\\Controls.h"

#include <ctime>

namespace GUIFramework
{

	#pragma region EventHandlers Forward Declarations

	static clock_t pressTime;

	std::vector<std::pair<std::string,clock_t>> NumberTimeArray;
	
	bool On_mButton_Click(int x, int y);

	bool On_mButton1_ClickUp(int x, int y);
	bool On_mButton1_ClickDown();
	bool On_mButton2_ClickUp(int x, int y);
	bool On_mButton2_ClickDown();
	bool On_mButton3_ClickUp(int x, int y);
	bool On_mButton3_ClickDown();

	bool On_mButton4_ClickUp(int x, int y);
	bool On_mButton4_ClickDown();
	bool On_mButton5_ClickUp(int x, int y);
	bool On_mButton5_ClickDown();
	bool On_mButton6_ClickUp(int x, int y);
	bool On_mButton6_ClickDown();

	bool On_mButton7_ClickUp(int x, int y);
	bool On_mButton7_ClickDown();
	bool On_mButton8_ClickUp(int x, int y);
	bool On_mButton8_ClickDown();
	bool On_mButton9_ClickUp(int x, int y);
	bool On_mButton9_ClickDown();

	bool On_mButtonAsterisk_ClickUp(int x, int y);
	bool On_mButtonAsterisk_ClickDown();
	bool On_mButton0_ClickUp(int x, int y);
	bool On_mButton0_ClickDown();
	bool On_mButtonNumeral_ClickUp(int x, int y);
	bool On_mButtonNumeral_ClickDown();

	bool On_mButtonAnalize_ClickUp(int x, int y);
	bool On_mButtonAnalize_ClickDown();

	#pragma endregion

		//Singleton Variable Initialization
	MyGUI* MyGUI::Singleton = NULL;

	MyGUI* MyGUI::GetSingleton()
		{
		if( !Singleton )
			Singleton = new MyGUI();

		return Singleton;	
		}

	//YOUR CODE HERE

	/*void MyGUI::ResolveEvents()
		{
		return;
		}*/

	void MyGUI::Load()
		{

			//Initialize you controls, and hang then from the GUI Tree

		/*mButton.SetPosition(AppPoint(50,50));
		mButton.SetCaption(std::wstring(L"Boton"));
		mButton.AddHandler(Button::HandlerType::OnMouseClickHType, (bool (*)(void))&On_mButton_Click);
		this->Controls.push_back(&mButton);*/

		mSlider.SetPosition(AppPoint(50,150));
		//this->Controls.push_back(&mSlider);

		//The numbers buttons
		wchar_t wStr[50];
		for( int i=0; i < 4; ++i)
			for(int j=0; j < 3; ++j)
			{
				GUIFramework::Button* pB = new GUIFramework::Button();
				pB->SetPosition( AppPoint(90+150*j,70*(i+1)) );
				switch( (i*3)+j+1 )
				{
				case 10:
					wcscpy(wStr, L"*");
					break;
				case 12:
					wcscpy(wStr, L"#");
					break;
				case 11:
					wcscpy(wStr, L"0");
					break;
				default:
					_itow((i*3)+j+1, wStr, 10);
					break;
				}
				pB->SetCaption( std::wstring(wStr) );
				
				mlButtonDial.push_back(pB);
				this->Controls.push_back(pB);
			}

			//The button to analize
			mAnalizePulses.SetPosition( AppPoint(90+150*1,70*(4+1)+20) );
			//mAnalizePulses.SetWidth(mAnalizePulses.GetWidth()+60);
			mAnalizePulses.SetCaption(L"Analizar Pulsos");
			this->Controls.push_back(&mAnalizePulses);

			mlButtonDial[0]->AddHandler(Button::HandlerType::OnMouseClickHType, (bool (*)(void))&On_mButton1_ClickUp);
			mlButtonDial[0]->AddHandler(Button::HandlerType::OnMouseClickDownHType, (bool (*)(void))&On_mButton1_ClickDown);
			mlButtonDial[1]->AddHandler(Button::HandlerType::OnMouseClickHType, (bool (*)(void))&On_mButton2_ClickUp);
			mlButtonDial[1]->AddHandler(Button::HandlerType::OnMouseClickDownHType, (bool (*)(void))&On_mButton2_ClickDown);
			mlButtonDial[2]->AddHandler(Button::HandlerType::OnMouseClickHType, (bool (*)(void))&On_mButton3_ClickUp);
			mlButtonDial[2]->AddHandler(Button::HandlerType::OnMouseClickDownHType, (bool (*)(void))&On_mButton3_ClickDown);

			mlButtonDial[3]->AddHandler(Button::HandlerType::OnMouseClickHType, (bool (*)(void))&On_mButton4_ClickUp);
			mlButtonDial[3]->AddHandler(Button::HandlerType::OnMouseClickDownHType, (bool (*)(void))&On_mButton4_ClickDown);
			mlButtonDial[4]->AddHandler(Button::HandlerType::OnMouseClickHType, (bool (*)(void))&On_mButton5_ClickUp);
			mlButtonDial[4]->AddHandler(Button::HandlerType::OnMouseClickDownHType, (bool (*)(void))&On_mButton5_ClickDown);
			mlButtonDial[5]->AddHandler(Button::HandlerType::OnMouseClickHType, (bool (*)(void))&On_mButton6_ClickUp);
			mlButtonDial[5]->AddHandler(Button::HandlerType::OnMouseClickDownHType, (bool (*)(void))&On_mButton6_ClickDown);

			mlButtonDial[6]->AddHandler(Button::HandlerType::OnMouseClickHType, (bool (*)(void))&On_mButton7_ClickUp);
			mlButtonDial[6]->AddHandler(Button::HandlerType::OnMouseClickDownHType, (bool (*)(void))&On_mButton7_ClickDown);
			mlButtonDial[7]->AddHandler(Button::HandlerType::OnMouseClickHType, (bool (*)(void))&On_mButton8_ClickUp);
			mlButtonDial[7]->AddHandler(Button::HandlerType::OnMouseClickDownHType, (bool (*)(void))&On_mButton8_ClickDown);
			mlButtonDial[8]->AddHandler(Button::HandlerType::OnMouseClickHType, (bool (*)(void))&On_mButton9_ClickUp);
			mlButtonDial[8]->AddHandler(Button::HandlerType::OnMouseClickDownHType, (bool (*)(void))&On_mButton9_ClickDown);

			mlButtonDial[9]->AddHandler(Button::HandlerType::OnMouseClickHType, (bool (*)(void))&On_mButtonAsterisk_ClickUp);
			mlButtonDial[9]->AddHandler(Button::HandlerType::OnMouseClickDownHType, (bool (*)(void))&On_mButtonAsterisk_ClickDown);
			mlButtonDial[10]->AddHandler(Button::HandlerType::OnMouseClickHType, (bool (*)(void))&On_mButton0_ClickUp);
			mlButtonDial[10]->AddHandler(Button::HandlerType::OnMouseClickDownHType, (bool (*)(void))&On_mButton0_ClickDown);
			mlButtonDial[11]->AddHandler(Button::HandlerType::OnMouseClickHType, (bool (*)(void))&On_mButtonNumeral_ClickUp);
			mlButtonDial[11]->AddHandler(Button::HandlerType::OnMouseClickDownHType, (bool (*)(void))&On_mButtonNumeral_ClickDown);

			mAnalizePulses.AddHandler(Button::HandlerType::OnMouseClickHType, (bool (*)(void))&On_mButtonAnalize_ClickUp);
			mAnalizePulses.AddHandler(Button::HandlerType::OnMouseClickDownHType, (bool (*)(void))&On_mButtonAnalize_ClickDown);

		}

	void MyGUI::UnLoad()
		{
			//Make any nessesary unitialization

		return;
		}

	void MyGUI::RenderGUI(const double elapsedTime)
		{
				//Our GUI will need alpha blending
			pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
			pDevice->SetRenderState(D3DRS_SRCBLEND , D3DBLEND_SRCALPHA);
			pDevice->SetRenderState(D3DRS_DESTBLEND , D3DBLEND_INVSRCALPHA);

				//Makes the rendering and the presentation of the backbuffer
			GUI::RenderGUI(elapsedTime);
			return;
		}

	#pragma region EventHandlers Section

	bool On_mButton_Click(int x, int y)
	{
		char txt[sizeof("You've click the button in (,). Congratulaitons!!! :D")+15];
		sprintf(txt,"You've click the button in (%i,%i). Congratulaitons!!! :D",x,y);
		MessageBoxA(NULL,txt, "We greets you", MB_OK);
		return true;
	}
	
	//PulseButtons Message Handlers BEGIN
	//--------------------

	bool On_mButton1_ClickDown()
	{
		//Adds Silence
		clock_t currentTime = clock();
		clock_t pressDeltaTime = (currentTime-pressTime) * (1.0/CLOCKS_PER_SEC);
		NumberTimeArray.push_back(std::pair<std::string,clock_t>("silencio",pressDeltaTime));

		//Plays pulse
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse1"]->Play();
		pressTime = clock();
		return true;
	}

	bool On_mButton1_ClickUp(int x, int y)
	{
		//Stop pulse
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse1"]->Stop();

		//Adds Number Pulse
		clock_t currentTime = clock();
		clock_t pressDeltaTime = (currentTime-pressTime) * (1.0/CLOCKS_PER_SEC);
		NumberTimeArray.push_back(std::pair<std::string,clock_t>("1",pressDeltaTime));

		//setup last this press
		pressTime = clock();
		return true;
	}

	bool On_mButton2_ClickDown()
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse2"]->Play();
		//Beep(550,1000);
		return true;
	}

	bool On_mButton2_ClickUp(int x, int y)
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse2"]->Stop();
		return true;
	}

	bool On_mButton3_ClickDown()
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse3"]->Play();
		//Beep(550,1000);
		return true;
	}

	bool On_mButton3_ClickUp(int x, int y)
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse3"]->Stop();
		return true;
	}

	bool On_mButton4_ClickDown()
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse4"]->Play();
		//Beep(550,1000);
		return true;
	}

	bool On_mButton4_ClickUp(int x, int y)
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse4"]->Stop();
		return true;
	}

	bool On_mButton5_ClickDown()
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse5"]->Play();
		//Beep(550,1000);
		return true;
	}

	bool On_mButton5_ClickUp(int x, int y)
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse5"]->Stop();
		return true;
	}

	bool On_mButton6_ClickDown()
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse6"]->Play();
		//Beep(550,1000);
		return true;
	}

	bool On_mButton6_ClickUp(int x, int y)
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse6"]->Stop();
		return true;
	}

	bool On_mButton7_ClickDown()
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse7"]->Play();
		//Beep(550,1000);
		return true;
	}

	bool On_mButton7_ClickUp(int x, int y)
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse7"]->Stop();
		return true;
	}

	bool On_mButton8_ClickDown()
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse8"]->Play();
		//Beep(550,1000);
		return true;
	}

	bool On_mButton8_ClickUp(int x, int y)
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse8"]->Stop();
		return true;
	}

	bool On_mButton9_ClickDown()
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse9"]->Play();
		//Beep(550,1000);
		return true;
	}

	bool On_mButton9_ClickUp(int x, int y)
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse9"]->Stop();
		return true;
	}

	bool On_mButtonAsterisk_ClickDown()
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["PulseAsterisk"]->Play();
		//Beep(550,1000);
		return true;
	}

	bool On_mButtonAsterisk_ClickUp(int x, int y)
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["PulseAsterisk"]->Stop();
		return true;
	}

	bool On_mButton0_ClickDown()
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse0"]->Play();
		//Beep(550,1000);
		return true;
	}

	bool On_mButton0_ClickUp(int x, int y)
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["Pulse0"]->Stop();
		return true;
	}

	bool On_mButtonNumeral_ClickDown()
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["PulseNumeral"]->Play();
		//Beep(550,1000);
		return true;
	}

	bool On_mButtonNumeral_ClickUp(int x, int y)
	{
		MyApp::GetSingleton()->pSoundBuffers->SoundDictionary["PulseNumeral"]->Stop();
		return true;
	}

	// The analize button
	bool On_mButtonAnalize_ClickDown()
	{
		
		return true;
	}

	bool On_mButtonAnalize_ClickUp(int x, int y)
	{

		// base time
		mwArray time(10000);
		//for( (int i=1, float pase=1/8000.0) ; i <= 10000 ; ++i )
		//	time(i) += pase;

		// Number array generated with base time
		mwArray Numbers(12,10000);
		for( int i=1; i <= 12 ; ++i)
		{
			int freq1=0;
			int freq2=0;
			switch( i )
			{
				case 1: //Numero1
                    freq1= 1209;
					freq2= 1209;
						break;
                case 2: //Numero2
                    freq1= 697;
					freq2= 1336;
						break;
                case 3: //Numero3
                    freq1= 697;
					freq2= 1477;
						break;
                case 4: //Numero4
                    freq1= 1209;
					freq2= 1209;
						break;
				case 5: //Numero5
                    freq1= 770;
					freq2= 1336;
						break;
				case 6: //Numero6
                    freq1= 770;
					freq2= 1477;
						break;
				case 7: //Numero7
                    freq1= 1209;
					freq2= 1209;
						break;
				case 8: //Numero8
                    freq1= 852;
					freq2= 1336;
						break;
				case 9: //Numero9
                    freq1= 852;
					freq2= 1477;
						break;
				case 10: //Numero10
                    freq1= 941;
					freq2= 1209;
						break;
				case 11: //Numero11
                    freq1= 941;
					freq2= 1336;
						break;
				case 12: //Numero12
                    freq1= 941;
					freq2= 1477;
						break;
			}

			for( int j=1; j <= 10000; ++j )
				int y=1;
				//Numbers(i,j) = sin(2*3.1415*freq1*time(j)) + sin(2*3.1415*freq2*time(j));

		}


		// Generating the pulse array with the input sequence
		int F = 8000;
		int count=0;
		for( int i=0;i < NumberTimeArray.size(); ++i )
			count += NumberTimeArray[i].second*F;
		mwArray Signal(count,1);

		int index=1;
		for( int i=0;i < NumberTimeArray.size(); ++i )
		{
			int num = 0;
			num = atoi(NumberTimeArray[i].first.c_str());
			int chunkSize = NumberTimeArray[i].second*F;
			for( int j=1; j <= chunkSize; ++j, ++index )
				Signal(index) = Numbers(num,j);
		}

		// Analizing the generated signal with Correlation
		mwArray Archivo("telefono\0");
		mwArray Ploted(0);
		mwArray* Sequencia = new mwArray();

		try
		{
		//AnalizarPulsos(1,*Sequencia,Archivo,Ploted);
		}catch( mwException e )
		{
			MyApp::GetSingleton()->Fatal(e.what(),0);
		}
		
		// Tells the analisis results
		//MessageBox(NULL, L"Luego del analisis, se concluyo que la secuencia presionada fue: " /*secuencia*/, L"Resultado de Analisis", MB_OK);

		return true;
	}
	

	//mButton		 END

	#pragma endregion

}