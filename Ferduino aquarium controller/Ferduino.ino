//------------------------------------ Menu 1 ----------------------------------------------------------- tela =1
void menuScreen()
{

  printHeader("MENU 1");

  printButton("DATE & TIME", tanD[0], tanD[1], tanD[2], tanD[3]);
  printButton("LED TEST", tesT[0], tesT[1], tesT[2], tesT[3]);
  printButton("PARAM. CONTROL", temC[0], temC[1], temC[2], temC[3]);
  printButton("GRAPHICS", graF[0], graF[1], graF[2], graF[3]);
  printButton("LED ADJUST", ledW[0], ledW[1], ledW[2], ledW[3]);
  printButton("AUTO ATO", tpaA[0], tpaA[1], tpaA[2], tpaA[3]);
  printButton("DOSING PUMPS", dosA[0], dosA[1], dosA[2], dosA[3]);
  printButton("WAVEMAKER", wavM[0], wavM[1], wavM[2], wavM[3]);
  printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
  printButton("MENU 2", menU[0], menU[1], menU[2], menU[3]);
}

// -------------------------CLOCK------------------------------------------------------ tela =2
void setClock()   
{
  t_temp = rtc.getTime();

  printHeader("TIME & DATE SET-UP");

  printButton ("+", houU[0], houU[1], houU[2], houU[3], true);   //hour up
  printButton ("-", houD[0], houD[1], houD[2], houD[3], true);   //hour down

  printButton ("+", minU[0], minU[1], minU[2], minU[3], true);   //min up
  printButton ("-", minD[0], minD[1], minD[2], minD[3], true);   //min down 

  printButton ("+", segC[0], segC[1], segC[2], segC[3], true);   //segundo mais
  printButton ("-", segB[0], segB[1], segB[2], segB[3], true);   //segundo menos

  printButton ("+", yeaU[0], yeaU[1], yeaU[2], yeaU[3], true);    //year up
  printButton ("-", yeaD[0], yeaD[1], yeaD[2], yeaD[3], true);     //year down

  printButton ("-", dayD[0], dayD[1], dayD[2], dayD[3], true);     //day down
  printButton ("+", dayU[0], dayU[1], dayU[2], dayU[3], true);    //day up

  printButton ("+", monU[0], monU[1], monU[2], monU[3], true);    //month up
  printButton ("-", monD[0], monD[1], monD[2], monD[3], true);     //month down

  printButton("SAVE", prOK[0], prOK[1], prOK[2], prOK[3]);
  printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
  printButton("MENU 1", menU[0], menU[1], menU[2], menU[3]);

  setFont(SMALL, 255, 255, 255, 0, 0, 0);
  myGLCD.print("HOUR:", 10, 51);
  myGLCD.print("DATE:", 10, 134); 

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.print(":", 120, 48);
  myGLCD.print(":", 210, 48);

  if (t_temp.hour<10)
  {
    myGLCD.printNumI(0, 70, 48);
    myGLCD.printNumI(t_temp.hour, 86, 48);
  }
  else
  {
    myGLCD.printNumI(t_temp.hour, 70, 48);
  } 
  if (t_temp.min<10)
  {
    myGLCD.printNumI(0, 160, 48);
    myGLCD.printNumI(t_temp.min, 176, 48);
  }
  else
  {
    myGLCD.printNumI(t_temp.min, 160, 48);
  } 
  if (t_temp.sec<10)
  {
    myGLCD.printNumI(0, 250, 48);
    myGLCD.printNumI(t_temp.sec, 266, 48);
  }
  else
  {
    myGLCD.printNumI(t_temp.sec, 250, 48);
  }
  if (t_temp.date<10)
  {
    myGLCD.printNumI(0, 70, 132);
    myGLCD.printNumI(t_temp.date, 86, 132);
  }
  else
  {
    myGLCD.printNumI(t_temp.date, 70, 132);
  }
  if (t_temp.mon<10)
  {
    myGLCD.printNumI(0, 160, 132);
    myGLCD.printNumI(t_temp.mon, 176, 132);
  }
  else
  {
    myGLCD.printNumI(t_temp.mon, 160, 132);
  }
  myGLCD.printNumI(t_temp.year, 230, 132);

}

void testScreen(boolean refreshAll=false)//-------------------------------- Led Testing ------------------------------------- tela =3
{    
  if (refreshAll == true) 
  {  
    printHeader("LIGHT LEVEL TEST");
    myGLCD.fillRect (1, 15, 318, 37);      //clear 'Test in progress'
    printButton ("", stsT[0], stsT[1], stsT[2], stsT[3], true);   //start/stop
    printButton ("-10s", tenM[0], tenM[1], tenM[2], tenM[3], true);     //-10s
    printButton ("+10s", tenP[0], tenP[1], tenP[2], tenP[3], true);   //+10s
    myGLCD.print("START", stsT[0]+10, stsT[1]+15);
    myGLCD.print("TEST", stsT[0]+25, stsT[1]+40);   
    printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("MENU 1", menU[0], menU[1], menU[2], menU[3]);
  } 
  else
  {
    printHeader("DIMMING LIGHT TEST");
    printButton ("", stsT[0], stsT[1], stsT[2], stsT[3], true);   //start/stop
    printButton ("-10s", tenM[0], tenM[1], tenM[2], tenM[3], true);     //-10s
    printButton ("+10s", tenP[0], tenP[1], tenP[2], tenP[3], true);   //+10s
    myGLCD.print("START", stsT[0]+10, stsT[1]+15);
    myGLCD.print("TEST", stsT[0]+25, stsT[1]+40);   
    min_cnt=0;

    /*    myGLCD.setColor(0, 0, 0);
     myGLCD.fillRect (1, 15, 318, 37);    //clear above buttons*/
    myGLCD.setColor(0, 0, 200);
    myGLCD.fillRect(stsT[0]+5, stsT[1]+5, stsT[2]-5, stsT[3]-40);   //clear 'start'
    setFont(LARGE, 255, 255, 255, 0, 0, 200);
    myGLCD.print("STOP", stsT[0]+25, stsT[1]+15);

    myGLCD.setColor(255, 0, 0);
    myGLCD.fillRect (1, 15, 318, 37);
    myGLCD.drawRoundRect (stsT[0], stsT[1], stsT[2], stsT[3]);       //red button during test
    setFont(LARGE, 255, 255, 255, 255, 0, 0);
    myGLCD.print("TEST IN PROGRESS", 15, 16);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("TEMPO:", 33, 40);
    myGLCD.print("OUTPUT POWER (0-255):", 30, 40);

    while (LEDtestTick == true)               //test LED and speed up time
    {
      if (myTouch.dataAvailable())  
      { 
        processMyTouch(); 
      }
      if (millis() - previousMillis > 500)    //change time every 0.5s
      {
        previousMillis = millis();
        min_cnt++;
        int hour = min_cnt/60;
        int minut = min_cnt%60;
        setFont(LARGE, 255, 255, 255, 0, 0, 0);
        myGLCD.print("  :  ", 20, 55);
        myGLCD.printNumI(hour, 24, 55);
        myGLCD.printNumI(minut, 64, 55);
        String bled = "B: " + String(bled_out) + "  ";      
        char bufferB[9];
        bled.toCharArray(bufferB, 9);
        myGLCD.print(bufferB, 180, 55);      //Blue led graph
        String wled = "W: " + String(wled_out) + "  ";
        char bufferW[9];
        wled.toCharArray(bufferW, 9);
        myGLCD.print(bufferW, 180, 75);

        LED_levels_output();

      }
    }
  } 
}

//--------------------------------------------- Temperature -------------------------------- tela =4 
void tempScreen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    if (setTempC==0) {
      setTempC = tempC;  
    }                  //change to current temp.
    temp2beS = setTempC;
    temp2beO = offTempC;
    temp2beA = alarmTempC;

    printHeader("WATER TEMP. CONTROL");

    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DESIRED TEMPERATURE:", 85, 20);
    myGLCD.print("PERMITED TEMP:", 90, 70);
    myGLCD.print("WATER TEMPERATURE ALARM:", 50, 120);

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus

    printButton("SAVE", prOK[0], prOK[1], prOK[2], prOK[3]);
    printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("BACK", menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.printNumF(temp2beS, 1, 130, 40);
  myGLCD.printNumF(temp2beO, 1, 140, 90);
  myGLCD.printNumF(temp2beA, 1, 140, 140);
}
void ledSetScreen()   //-------------------------------- Change values ----------------------------------- tela =5
{
  int a;

  if (WorB) {
    for (int i; i<96; i++)
      tled[i] = wled[i];
    setFont(SMALL, 255, 255, 0, 255, 255, 0);
    myGLCD.fillRect (1, 1, 318, 14);
    myGLCD.setColor(0, 0, 0);
    myGLCD.print("WHITE LED POWER: 255 = 100%",15, 2);
    printButton("BLUE", leWB[0], leWB[1], leWB[2], leWB[3], SMALL);
  }
  else {
    for (int i; i<96; i++)
      tled[i] = bled[i];
    setFont(SMALL, 255, 255, 0, 255, 255, 0);
    myGLCD.fillRect (1, 1, 318, 14);
    myGLCD.setColor(0, 0, 0);
    myGLCD.print("BLUE LED POWER: 255 = 100%" ,15, 2);
    printButton("WHITE", leWB[0], leWB[1], leWB[2], leWB[3], SMALL);
  }

  setFont(SMALL, 255, 255, 255, 0, 0, 0);
  for (int i=0; i<12; i++) {
    myGLCD.setColor(0, 255, 255);
    myGLCD.printNumI((i*2), (i*26)+13, 14); 
    myGLCD.printNumI(((i*2)+2), (i*26)+13, 24);
    for (int j=0; j<8; j++) {
      a= (i*8)+j;         
      myGLCD.setColor(255, 255, 255);
      myGLCD.printNumI(tled[a], (i*26)+7, (j*18)+39);
      myGLCD.setColor(100, 100, 100);
      myGLCD.drawRect((i*26)+4, (j*18)+35, (i*26)+30, (j*18)+53);
    }
  }

  printButton("CHANGE", leST[0], leST[1], leST[2], leST[3], SMALL);
  printButton("SAVE EEPROM", savE[0], savE[1], savE[2], savE[3], SMALL);
  printButton("MENU 1", menU[0], menU[1], menU[2], menU[3]);
  printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);

}
void ledChangeScreen()    //--------------------------------------- Led Power------------------------------ tela =6
{
  if (WorB)
    printHeader("WHITE LEDS INTENSITY CHANGE");
  else
    printHeader("BLUE LEDS INTENSITY CHANGE");

  setFont(SMALL, 0, 255, 255, 0,0,0);
  for (int i=0; i<12; i++) {
    myGLCD.setColor(0, 255, 255);
    myGLCD.printNumI(((i*2)), (i*26)+10, 22);
    myGLCD.printNumI(((i*2)+2), (i*26)+10, 33);
    myGLCD.setColor(100, 100, 100);
    myGLCD.drawRect((i*26)+4, 20 , (i*26)+30, 45);
  }

  for (int i=0; i<8; i++)
  {
    printButton("+", (i*38)+10, 70, (i*38)+35, 95, LARGE);
    printButton("-", (i*38)+10, 125, (i*38)+35, 150, LARGE);
  }

  printButton("SAVE", prOK[0], prOK[1], prOK[2], prOK[3]);
  printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
  printButton("MENU 1", menU[0], menU[1], menU[2], menU[3]);
}
void tpaScreen(boolean refreshAll = false) //-------------------------------------------------------- tela =7
{
  if(refreshAll)
  {
    temp2hora = hora;
    temp2minuto = minuto;
    temp2duracaomaximatpa = duracaomaximatpa;
    temp2segunda = segunda;
    temp2terca = terca;
    temp2quarta = quarta;
    temp2quinta = quinta;
    temp2sexta = sexta;
    temp2sabado = sabado;
    temp2domingo = domingo;

    printHeader("CONF. TIME & DATE FOR AUTO TOP OFF");

    printButton("+", houU[0], houU[1], houU[2], houU[3], true); //hour up
    printButton("-", houD[0], houD[1], houD[2], houD[3], true); //hour down
    printButton("+", minUT[0], minUT[1], minUT[2], minUT[3], true); //min up
    printButton("-", minDT[0], minDT[1], minDT[2], minDT[3], true); //min down
    printButton("+", durC[0], durC[1], durC[2], durC[3], true); //min up
    printButton("-", durB[0], durB[1], durB[2], durB[3], true); //min down

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.print(":", 105, 48);
    myGLCD.setFont(SmallFont);
    myGLCD.print("HOUR:", 10, 51);
    myGLCD.print("MAXIMUM DURATION", 157, 31);
    myGLCD.print("POR ESTAGIO:", 170, 46);
    printButton("SAVE", prOK[0], prOK[1], prOK[2], prOK[3]);
    printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("MENU 1", menU[0], menU[1], menU[2], menU[3]);
  }
  if (temp2segunda == 1) {
    printButton_verde("MONDAY", segU[0], segU[1], segU[2], segU[3]); //botao segunda
  } 
  else {
    printButton("MONDAY", segU[0], segU[1], segU[2], segU[3]); //botao segunda
  }
  if (temp2terca == 2) {
    printButton_verde("TUESDAY ", terC[0], terC[1], terC[2], terC[3]); //botao terca
  } 
  else {
    printButton("TUESDAY ", terC[0], terC[1], terC[2], terC[3]); //botao terca
  }
  if (temp2quarta == 3) {
    printButton_verde("WEDNESDAY", quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
  } 
  else {
    printButton("WEDNESDAY", quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
  }
  if (temp2quinta == 4) {
    printButton_verde("THURSDAY", quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
  } 
  else {
    printButton("THURSDAY", quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
  }
  if (temp2sexta == 5) {
    printButton_verde("FRIDAY", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
  } 
  else {
    printButton("FRIDAY", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
  }
  if (temp2sabado == 6) printButton_verde("SATURDAY", sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
  else {
    printButton("SATURDAY", sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
  }
  if (temp2domingo == 7) printButton_verde("SUNDAY", domI[0], domI[1], domI[2], domI[3]); //botao domingo
  else {
    printButton("SUNDAY", domI[0], domI[1], domI[2], domI[3]); //botao domingo
  }
  if (falha_tpa == true) {
    printButton_vermelho("FALHA!!", proX[0], proX[1], proX[2], proX[3]); //Sinaliza que houve uma falha durante a TPA.
  } 
  else {
    printButton("NORMAL", proX[0], proX[1], proX[2], proX[3]); //Sinaliza que a TPA foi realizada normalmente ou não foi realizada.
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  if (temp2hora < 10) {
    myGLCD.printNumI(0, 70, 48);
    myGLCD.printNumI(temp2hora, 86, 48);
  } 
  else {
    myGLCD.printNumI(temp2hora, 70, 48);
  }

  if (temp2minuto < 10) {
    myGLCD.printNumI(0, 120, 48);
    myGLCD.printNumI(temp2minuto, 136, 48);
  } 
  else {
    myGLCD.printNumI(temp2minuto, 120, 48);
  }
  if (temp2duracaomaximatpa < 10) {
    myGLCD.printNumI(0, 275, 48);
    myGLCD.printNumI(temp2duracaomaximatpa, 291, 48);
  } 
  else {
    myGLCD.printNumI(temp2duracaomaximatpa, 275, 48);
  }  
}
void menu_dosadoras()//---------------------------------------------tela =8
{

  printHeader("DOSING PUMP SET-UP");

  printButton("MANUAL", manU[0], manU[1], manU[2], manU[3]);
  printButton("AUTOMATIC", autO[0], autO[1], autO[2], autO[3]);
  printButton("PERSONALIZED", perS[0], perS[1], perS[2], perS[3]);
  printButton("REVER CONFIG.", reV[0], reV[1], reV[2], reV[3]);
  printButton("MODE DEACTIVATION", atiV[0], atiV[1], atiV[2], atiV[3]);
  printButton("CALIBRATE", caliB[0], caliB[1], caliB[2], caliB[3]);
  printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
  printButton("MENU 1", menU[0], menU[1], menU[2], menU[3]);
}

void graficoScreen()//------------------------------------------------------------tela =9
{  
  printHeader("CHOOSE A GRAPH"); 
  printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]); 
  printButton("MENU 1", menU[0], menU[1], menU[2], menU[3]);
  printButton("TEMPERATURE", tempG[0], tempG[1], tempG[2],tempG[3]);
  printButton("TANK PH", phA[0], phA[1], phA[2], phA[3]);
  printButton("REACTOR PH", phR[0], phR[1], phR[2], phR[3]);
  printButton("ORP", orP[0], orP[1], orP[2], orP[3]);
  printButton("SALNITY", denS[0], denS[1], denS[2], denS[3]);

}

void waveScreen(boolean refreshAll=false)///------------------------------------------------------------------tela =10
{
  printHeader("WAVEMAKER");
  printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
  printButton("MENU 1", menU[0], menU[1], menU[2], menU[3]);

  setFont(SMALL, 255, 255, 255, 0, 0, 0);
  myGLCD.print("INCOMPLETE FUNCTION", 80, 30);
}
void parametroScreen()//------------------------------------------------------------tela =14---------
{  
  printHeader("CHOOSE A PARAMETER"); 
  printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3],false); 
  printButton("MENU 1", menU[0], menU[1], menU[2], menU[3],false);
  printButton("TEMPERATURE", tempG[0], tempG[1], tempG[2],tempG[3]);
  printButton("TANK PH", phA[0], phA[1], phA[2], phA[3]);
  printButton("REACTOR PH", phR[0], phR[1], phR[2], phR[3]);
  printButton("ORP", orP[0], orP[1], orP[2], orP[3]);
  printButton("SALINITY", denS[0], denS[1], denS[2], denS[3]);
  printButton("PROBE CALIBRATION", caliB[0], caliB[1], caliB[2], caliB[3]);

}
//---------------------------------------------PH do reator--------------------------------tela =15 ----------
void config_phR_Screen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    if (setPHR==0) {
      setPHR = PHR;  
    }                  //change to current temp.
    PHR2beS = setPHR;
    PHR2beO = offPHR;
    PHR2beA = alarmPHR;

    printHeader("CA. REACTOR PH CONTROL");

    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DESIRED PH:", 110, 20);
    myGLCD.print("PERMITED VALUE:", 90, 70);
    myGLCD.print("ALARM PH VALUE:", 50, 120);

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus

    printButton("SAVE", prOK[0], prOK[1], prOK[2], prOK[3]);
    printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("BACK", menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.printNumF(PHR2beS, 1, 135, 40);
  myGLCD.printNumF(PHR2beO, 1, 140, 90);
  myGLCD.printNumF(PHR2beA, 1, 140, 140);
}

//---------------------------------------------ORP--------------------------------tela =16 ----------
void config_orp_Screen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    ORP2beS = setORP;
    ORP2beO = offORP;
    ORP2beA = alarmORP;

    printHeader("ORP CONTROL");

    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DESIRED ORP:", 115, 20);
    myGLCD.print("PERMITED VARIATION:", 90, 70);
    myGLCD.print("ORP ALARM VALUE:", 50, 120);

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus

    printButton("SAVE", prOK[0], prOK[1], prOK[2], prOK[3]);
    printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("BACK", menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.printNumI(ORP2beS,145, 40);
  myGLCD.printNumI(ORP2beO,150, 90);
  myGLCD.printNumI(ORP2beA, 150, 140);
}
//---------------------------------------------Tank PH--------------------------------tela =18 ----------

void config_phA_Screen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    if (setPHA==0) {
      setPHA = PHA;  
    }                  //change to current temp.
    PHA2beS = setPHA;
    PHA2beO = offPHA;
    PHA2beA = alarmPHA;

    printHeader("TANK PH CONTROL");

    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DESIRED PH:", 110, 20);
    myGLCD.print("PERMITED PH:", 90, 70);
    myGLCD.print("PH ALARM VALUE:", 50, 120);
    /* myGLCD.print("NAO HA FUNCAO DE CONTROLE", 25, 170);
     myGLCD.print("ATTRIBUTE FOR THIS PARAMETER", 25, 185);
     myGLCD.print("THESE VALUES ARE JUST ", 25, 200);
     myGLCD.print("REFERENCE FOR THE GRAPH.", 25, 215);**/

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus

    printButton("SAVE", prOK[0], prOK[1], prOK[2], prOK[3]);
    printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("BACK", menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0); 
  myGLCD.printNumF(PHA2beS, 1, 135, 40);
  myGLCD.printNumF(PHA2beO, 1, 140, 90);
  myGLCD.printNumF(PHA2beA, 1, 140, 140);
}
//---------------------------------------------Salinity Configuration--------------------------------tela =20 ----------
void config_dens_Screen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    DEN2beS = setDEN;
    DEN2beO = offDEN;
    DEN2beA = alarmDEN;

    printHeader("SALINITY CONTROL");

    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DESIRED SALINITY:", 90, 20);
    myGLCD.print("PERMITED SALINITY:", 90, 70);
    myGLCD.print("SALINITY ALARM VALUE:", 50, 120);
    /*  myGLCD.print("NAO HA FUNCAO DE CONTROLE", 25, 170);
     myGLCD.print("ATRIBUIDA PARA ESTE PARAMETRO", 25, 185);
     myGLCD.print("THESE VALUES ARE JUST", 25, 200);
     myGLCD.print("REFERENCE FOR THE GRAPH.", 25, 215);*/

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus

    printButton("SAVE", prOK[0], prOK[1], prOK[2], prOK[3]);
    printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("BACK", menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0); 
  myGLCD.printNumI(DEN2beS, 128, 40);
  myGLCD.printNumI(DEN2beO, 150, 90);
  myGLCD.printNumI(DEN2beA, 150, 140);
}

void selecionar_dosadora(boolean refreshAll=false)//---------------------------------------------tela =21
{
  printHeader("CHOOSE A DOSING PUMP");
  printButton("PUMP 1", dosa1[0], dosa1[1], dosa1[2], dosa1[3]);
  printButton("PUMP 2", dosa2[0], dosa2[1], dosa2[2], dosa2[3]);
  printButton("PUMP 3", dosa3[0], dosa3[1], dosa3[2], dosa3[3]);
  printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
  printButton("MENU 1", menU[0], menU[1], menU[2], menU[3]);
  printButton("BACK", volT[0], volT[1], volT[2], volT[3]);  
}

//---------------------------------------- Dosing Pump Calibration ---------------------- tela =26 
void calibrar_dosadoras(boolean refreshAll=false)
{
  if(refreshAll)
  {
    fator_calib_dosadora_1_temp2 = fator_calib_dosadora_1;
    fator_calib_dosadora_2_temp2 = fator_calib_dosadora_2;
    fator_calib_dosadora_3_temp2 = fator_calib_dosadora_3;

    printHeader("DOSING PUMP CALIBRATION");
    printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("BACK", volT[0], volT[1], volT[2], volT[3]);
    printButton("SAVE", salV[0], salV[1], salV[2], salV[3]);
    printButton("START", iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus  
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(20, 50, 310, 125);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PUT CONTAINER UNDER THE NOZZLE", 30, 55);
    myGLCD.print("PRESS TO START.", 30, 70);  
    myGLCD.print("AFTER INSERT OBTAINED VALUE", 30, 85);
    myGLCD.print("ML IN THE FIELD BELOW.", 30, 100);
    myGLCD.print("FOR BEST RESULTS REPEAT THE TEST", 5, 165);
    myGLCD.print("ALGUMAS VEZES E USE UMA MEDIA.", 35, 177);
  }
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(117, 135, 203, 160);

  if((modo_calibrar == true) && (dosadora_1_selecionada == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(fator_calib_dosadora_1_temp2,1, 130, 140);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PUMP 1 SELECTED", 80, 30);
  }

  if((modo_calibrar == true) && (dosadora_2_selecionada == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(fator_calib_dosadora_2_temp2,1, 130, 140);  
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PUMP 2 SELECTED", 80, 30);
  }

  if((modo_calibrar == true) && (dosadora_3_selecionada == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(fator_calib_dosadora_3_temp2,1, 130, 140);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PUMP 3 SELECTED", 80, 30);
  } 
}

void config_dosagem_manual(boolean refreshAll=false) // ----------tela =27
{
  if(refreshAll)
  {
    printHeader("MANUAL DOSING");
    printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("BACK", volT[0], volT[1], volT[2], volT[3]);
    printButton("START", iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus  
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(20, 50, 310, 125);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("SELECT A QUANTITY FOR DOSING", 30, 55);
    myGLCD.print("ML IN THE FIELD BELOW", 30, 70);  
    myGLCD.print("START AFTER TOUCH.", 30, 85);
    myGLCD.print("DOSING STARTS IN 10 SECONDS", 30, 100);
  }
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(117, 135, 203, 160);

  if((modo_manual == true) && (dosadora_1_selecionada == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_1_manual,1, 130, 140);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PUMP 1 SELECTED", 80, 30);
  }

  if((modo_manual == true) && (dosadora_2_selecionada == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_2_manual,1, 130, 140);  
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PUMP 2 SELECTED", 80, 30);
  }

  if((modo_manual == true) && (dosadora_3_selecionada == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_3_manual,1, 130, 140);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PUMP 3 SELECTED", 80, 30);
  } 
}

void config_dosagem_automatica(boolean refreshAll=false) // ----------tela =28
{
  if(refreshAll)
  { 
    hora_inicial_dosagem_automatica_1_temp2 = hora_inicial_dosagem_automatica_1;
    minuto_inicial_dosagem_automatica_1_temp2 = minuto_inicial_dosagem_automatica_1;
    hora_final_dosagem_automatica_1_temp2 = hora_final_dosagem_automatica_1;
    minuto_final_dosagem_automatica_1_temp2 = minuto_final_dosagem_automatica_1;
    hora_inicial_dosagem_automatica_2_temp2 = hora_inicial_dosagem_automatica_2;
    minuto_inicial_dosagem_automatica_2_temp2 = minuto_inicial_dosagem_automatica_2;
    hora_final_dosagem_automatica_2_temp2 = hora_final_dosagem_automatica_2;
    minuto_final_dosagem_automatica_2_temp2 = minuto_final_dosagem_automatica_2;
    hora_inicial_dosagem_automatica_3_temp2 = hora_inicial_dosagem_automatica_3;
    minuto_inicial_dosagem_automatica_3_temp2 = minuto_inicial_dosagem_automatica_3;
    hora_final_dosagem_automatica_3_temp2 = hora_final_dosagem_automatica_3;
    minuto_final_dosagem_automatica_3_temp2 = minuto_final_dosagem_automatica_3;
    dose_dosadora_1_automatica_temp2 = dose_dosadora_1_automatica;
    dose_dosadora_2_automatica_temp2 = dose_dosadora_2_automatica;
    dose_dosadora_3_automatica_temp2 = dose_dosadora_3_automatica;
    quantidade_dose_dosadora_1_automatica_temp2 = quantidade_dose_dosadora_1_automatica;
    quantidade_dose_dosadora_2_automatica_temp2 = quantidade_dose_dosadora_2_automatica;
    quantidade_dose_dosadora_3_automatica_temp2 = quantidade_dose_dosadora_3_automatica;
    modo_automatico_on_1_temp2 = modo_automatico_on_1;
    modo_automatico_on_2_temp2 = modo_automatico_on_2;
    modo_automatico_on_3_temp2 = modo_automatico_on_3;
    modo_personalizado_on_1_temp2 = modo_personalizado_on_1;
    modo_personalizado_on_2_temp2 = modo_personalizado_on_2;
    modo_personalizado_on_3_temp2 = modo_personalizado_on_3;

    printHeader("AUTOMATIC DOSING CONFIGURATION");

    printButton("+", houU[0], houU[1], houU[2], houU[3], true); //hour up
    printButton("-", houD[0], houD[1], houD[2], houD[3], true); //hour down
    printButton("+", minUT[0], minUT[1], minUT[2], minUT[3], true); //min up
    printButton("-", minDT[0], minDT[1], minDT[2], minDT[3], true); //min down
    printButton("+", houU[0]+deslocamento_botao_x, houU[1], houU[2]+deslocamento_botao_x, houU[3], true); //hora mais
    printButton("-", houD[0]+deslocamento_botao_x, houD[1], houD[2]+deslocamento_botao_x, houD[3], true); //hora menos
    printButton("+", minUT[0]+deslocamento_botao_x, minUT[1], minUT[2]+deslocamento_botao_x, minUT[3], true); //minuto mais
    printButton("-", minDT[0]+deslocamento_botao_x, minDT[1], minDT[2]+deslocamento_botao_x, minDT[3], true); //minuto menos
    printButton("+", minUT[0], minUT[1]+deslocamento_botao_y, minUT[2], minUT[3]+deslocamento_botao_y, true); //min up
    printButton("-", minDT[0], minDT[1]+deslocamento_botao_y, minDT[2], minDT[3]+deslocamento_botao_y, true); //min down
    printButton("+", durC[0], durC[1]+deslocamento_botao_y, durC[2], durC[3]+deslocamento_botao_y, true); //minuto mais
    printButton("-", durB[0], durB[1]+deslocamento_botao_y, durB[2], durB[3]+deslocamento_botao_y, true); //minuto menos

    printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("BACK", volT[0], volT[1], volT[2], volT[3]);
    printButton("SAVE", salV[0], salV[1], salV[2], salV[3]);

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.print(":", 105, 48);
    myGLCD.print(":", 105 + deslocamento_botao_x, 48);
    myGLCD.setFont(SmallFont);
    myGLCD.print("INITIAL:", 5, 51);
    myGLCD.print("FINAL:", 172, 51);
    myGLCD.print("SELECIONE O", 10, 31 + deslocamento_botao_y);
    myGLCD.print("VOLUME ", 10, 55 + deslocamento_botao_y);
    myGLCD.print("(ML/DAY):", 10, 75 + deslocamento_botao_y);
    myGLCD.print("QUANTITY", 190, 46 + deslocamento_botao_y);
    myGLCD.print("DOSES NR.:", 190, 61 + deslocamento_botao_y);
  }

  if(dosadora_1_selecionada == true)
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    if (hora_inicial_dosagem_automatica_1_temp2 < 10) {
      myGLCD.printNumI(0, 70, 48);
      myGLCD.printNumI(hora_inicial_dosagem_automatica_1_temp2, 86, 48);
    } 
    else {
      myGLCD.printNumI(hora_inicial_dosagem_automatica_1_temp2, 70, 48);
    }

    if (minuto_inicial_dosagem_automatica_1_temp2 < 10) {
      myGLCD.printNumI(0, 120, 48);
      myGLCD.printNumI(minuto_inicial_dosagem_automatica_1_temp2, 136, 48);
    } 
    else {
      myGLCD.printNumI(minuto_inicial_dosagem_automatica_1_temp2, 120, 48);
    }
    if (hora_final_dosagem_automatica_1_temp2 < 10) {
      myGLCD.printNumI(0, 70 + deslocamento_botao_x, 48);
      myGLCD.printNumI(hora_final_dosagem_automatica_1_temp2, 86 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(hora_final_dosagem_automatica_1_temp2, 70 + deslocamento_botao_x, 48);
    }

    if (minuto_final_dosagem_automatica_1_temp2 < 10) {
      myGLCD.printNumI(0, 120 + deslocamento_botao_x, 48);
      myGLCD.printNumI(minuto_final_dosagem_automatica_1_temp2, 136 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(minuto_final_dosagem_automatica_1_temp2, 120 + deslocamento_botao_x, 48);
    }

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    myGLCD.printNumF(dose_dosadora_1_automatica_temp2, 1, 100, 48 + deslocamento_botao_y);

    if (quantidade_dose_dosadora_1_automatica_temp2 < 10) 
    {
      myGLCD.printNumI(0, 275, 48 + deslocamento_botao_y);
      myGLCD.printNumI(quantidade_dose_dosadora_1_automatica_temp2, 291, 48 + deslocamento_botao_y);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_1_automatica_temp2, 275, 48 + deslocamento_botao_y);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PUMP 1", 10, 198);
    myGLCD.print("SELECTED", 10, 218);

    if (modo_automatico_on_1_temp2 == 1) 
    {
      printButton_verde("ON", domI[0], domI[1], domI[2], domI[3]); 
    } 
    else 
    {
      printButton("OFF", domI[0], domI[1], domI[2], domI[3]); 
    }
  }
  if(dosadora_2_selecionada == true)
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    if (hora_inicial_dosagem_automatica_2_temp2 < 10) {
      myGLCD.printNumI(0, 70, 48);
      myGLCD.printNumI(hora_inicial_dosagem_automatica_2_temp2, 86, 48);
    } 
    else {
      myGLCD.printNumI(hora_inicial_dosagem_automatica_2_temp2, 70, 48);
    }

    if (minuto_inicial_dosagem_automatica_2_temp2 < 10) {
      myGLCD.printNumI(0, 120, 48);
      myGLCD.printNumI(minuto_inicial_dosagem_automatica_2_temp2, 136, 48);
    } 
    else {
      myGLCD.printNumI(minuto_inicial_dosagem_automatica_2_temp2, 120, 48);
    }
    if (hora_final_dosagem_automatica_2_temp2 < 10) {
      myGLCD.printNumI(0, 70 + deslocamento_botao_x, 48);
      myGLCD.printNumI(hora_final_dosagem_automatica_2_temp2, 86 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(hora_final_dosagem_automatica_2_temp2, 70 + deslocamento_botao_x, 48);
    }

    if (minuto_final_dosagem_automatica_2_temp2 < 10) {
      myGLCD.printNumI(0, 120 + deslocamento_botao_x, 48);
      myGLCD.printNumI(minuto_final_dosagem_automatica_2_temp2, 136 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(minuto_final_dosagem_automatica_2_temp2, 120 + deslocamento_botao_x, 48);
    }
    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    myGLCD.printNumF(dose_dosadora_2_automatica_temp2, 1, 100, 48 + deslocamento_botao_y);

    if (quantidade_dose_dosadora_2_automatica_temp2 < 10) 
    {
      myGLCD.printNumI(0, 275, 48 + deslocamento_botao_y);
      myGLCD.printNumI(quantidade_dose_dosadora_2_automatica_temp2, 291, 48 + deslocamento_botao_y);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_2_automatica_temp2, 275, 48 + deslocamento_botao_y);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PUMP 2", 10, 198);
    myGLCD.print("SELECTED", 10, 218);

    if (modo_automatico_on_2_temp2 == 1) 
    {
      printButton_verde("ON", domI[0], domI[1], domI[2], domI[3]); 
    } 
    else 
    {
      printButton("OFF", domI[0], domI[1], domI[2], domI[3]); 
    }
  }
  if(dosadora_3_selecionada == true)
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    if (hora_inicial_dosagem_automatica_3_temp2 < 10) {
      myGLCD.printNumI(0, 70, 48);
      myGLCD.printNumI(hora_inicial_dosagem_automatica_3_temp2, 86, 48);
    } 
    else {
      myGLCD.printNumI(hora_inicial_dosagem_automatica_3_temp2, 70, 48);
    }

    if (minuto_inicial_dosagem_automatica_3_temp2 < 10) {
      myGLCD.printNumI(0, 120, 48);
      myGLCD.printNumI(minuto_inicial_dosagem_automatica_3_temp2, 136, 48);
    } 
    else {
      myGLCD.printNumI(minuto_inicial_dosagem_automatica_3_temp2, 120, 48);
    }
    if (hora_final_dosagem_automatica_3_temp2 < 10) {
      myGLCD.printNumI(0, 70 + deslocamento_botao_x, 48);
      myGLCD.printNumI(hora_final_dosagem_automatica_3_temp2, 86 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(hora_final_dosagem_automatica_3_temp2, 70 + deslocamento_botao_x, 48);
    }

    if (minuto_final_dosagem_automatica_3_temp2 < 10) {
      myGLCD.printNumI(0, 120 + deslocamento_botao_x, 48);
      myGLCD.printNumI(minuto_final_dosagem_automatica_3_temp2, 136 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(minuto_final_dosagem_automatica_3_temp2, 120 + deslocamento_botao_x, 48);
    }
    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    myGLCD.printNumF(dose_dosadora_3_automatica_temp2, 1, 100, 48 + deslocamento_botao_y);

    if (quantidade_dose_dosadora_3_automatica_temp2 < 10) 
    {
      myGLCD.printNumI(0, 275, 48 + deslocamento_botao_y);
      myGLCD.printNumI(quantidade_dose_dosadora_3_automatica_temp2, 291, 48 + deslocamento_botao_y);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_3_automatica_temp2, 275, 48 + deslocamento_botao_y);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PUMP 3", 10, 198);
    myGLCD.print("SELECTED", 10, 218);

    if (modo_automatico_on_3_temp2 == 1) 
    {
      printButton_verde("ON", domI[0], domI[1], domI[2], domI[3]); 
    } 
    else 
    {
      printButton("OFF", domI[0], domI[1], domI[2], domI[3]); 
    }
  }  
  myGLCD.setColor(0, 0, 0);                      
  myGLCD.fillRect(205, 195, 310, 239);
}

void config_dosagem_personalizada(boolean refreshAll=false) // ----------tela =29
{
  if(refreshAll)
  {   

    temp2hora_inicial_dosagem_personalizada_1 = hora_inicial_dosagem_personalizada_1;
    temp2minuto_inicial_dosagem_personalizada_1 = minuto_inicial_dosagem_personalizada_1;
    temp2hora_final_dosagem_personalizada_1 = hora_final_dosagem_personalizada_1;
    temp2minuto_final_dosagem_personalizada_1 = minuto_final_dosagem_personalizada_1;
    temp2segunda_dosagem_personalizada_1 = segunda_dosagem_personalizada_1;
    temp2terca_dosagem_personalizada_1 = terca_dosagem_personalizada_1;
    temp2quarta_dosagem_personalizada_1 = quarta_dosagem_personalizada_1;
    temp2quinta_dosagem_personalizada_1 = quinta_dosagem_personalizada_1;
    temp2sexta_dosagem_personalizada_1 = sexta_dosagem_personalizada_1;
    temp2sabado_dosagem_personalizada_1 = sabado_dosagem_personalizada_1;
    temp2domingo_dosagem_personalizada_1 = domingo_dosagem_personalizada_1;
    temp2hora_inicial_dosagem_personalizada_2 = hora_inicial_dosagem_personalizada_2;
    temp2minuto_inicial_dosagem_personalizada_2 = minuto_inicial_dosagem_personalizada_2;
    temp2hora_final_dosagem_personalizada_2 = hora_final_dosagem_personalizada_2;
    temp2minuto_final_dosagem_personalizada_2 = minuto_final_dosagem_personalizada_2;
    temp2segunda_dosagem_personalizada_2 = segunda_dosagem_personalizada_2;
    temp2terca_dosagem_personalizada_2 = terca_dosagem_personalizada_2;
    temp2quarta_dosagem_personalizada_2 = quarta_dosagem_personalizada_2;
    temp2quinta_dosagem_personalizada_2 = quinta_dosagem_personalizada_2;
    temp2sexta_dosagem_personalizada_2 = sexta_dosagem_personalizada_2;
    temp2sabado_dosagem_personalizada_2 = sabado_dosagem_personalizada_2;
    temp2domingo_dosagem_personalizada_2 = domingo_dosagem_personalizada_2;
    temp2hora_inicial_dosagem_personalizada_3 = hora_inicial_dosagem_personalizada_3;
    temp2minuto_inicial_dosagem_personalizada_3 = minuto_inicial_dosagem_personalizada_3;
    temp2hora_final_dosagem_personalizada_3 = hora_final_dosagem_personalizada_3;
    temp2minuto_final_dosagem_personalizada_3 = minuto_final_dosagem_personalizada_3;
    temp2segunda_dosagem_personalizada_3 = segunda_dosagem_personalizada_3;
    temp2terca_dosagem_personalizada_3 = terca_dosagem_personalizada_3;
    temp2quarta_dosagem_personalizada_3 = quarta_dosagem_personalizada_3;
    temp2quinta_dosagem_personalizada_3 = quinta_dosagem_personalizada_3;
    temp2sexta_dosagem_personalizada_3 = sexta_dosagem_personalizada_3;
    temp2sabado_dosagem_personalizada_3 = sabado_dosagem_personalizada_3;
    temp2domingo_dosagem_personalizada_3 = domingo_dosagem_personalizada_3;

    printHeader("PERSONALIZED DOSING CONFIGURATION");

    printButton("+", houU[0], houU[1], houU[2], houU[3], true); //hour up
    printButton("-", houD[0], houD[1], houD[2], houD[3], true); //hour down
    printButton("+", minUT[0], minUT[1], minUT[2], minUT[3], true); //min up
    printButton("-", minDT[0], minDT[1], minDT[2], minDT[3], true); //min down
    printButton("+", houU[0]+deslocamento_botao_x, houU[1], houU[2]+deslocamento_botao_x, houU[3], true); //hora mais
    printButton("-", houD[0]+deslocamento_botao_x, houD[1], houD[2]+deslocamento_botao_x, houD[3], true); //hora menos
    printButton("+", minUT[0]+deslocamento_botao_x, minUT[1], minUT[2]+deslocamento_botao_x, minUT[3], true); //minuto mais
    printButton("-", minDT[0]+deslocamento_botao_x, minDT[1], minDT[2]+deslocamento_botao_x, minDT[3], true); //minuto menos

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.print(":", 105, 48);
    myGLCD.print(":", 105 + deslocamento_botao_x, 48);
    myGLCD.setFont(SmallFont);
    myGLCD.print("INITIAL:", 5, 51);
    myGLCD.print("FINAL:", 172, 51);
    printButton("NEXT", proX[0], proX[1], proX[2], proX[3]); 
    printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("MENU 1", menU[0], menU[1], menU[2], menU[3]);
    printButton("BACK", volT[0], volT[1], volT[2], volT[3]);
  }
  if(dosadora_1_selecionada == true)
  {
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PUMP 1", 10, 198);
    myGLCD.print("SELECTED", 10, 218);

    if (temp2segunda_dosagem_personalizada_1 == 1) {
      printButton_verde("MONDAY", segU[0], segU[1], segU[2], segU[3]); //botao segunda
    } 
    else {
      printButton("MONDAY", segU[0], segU[1], segU[2], segU[3]); //botao segunda
    }
    if (temp2terca_dosagem_personalizada_1 == 2) {
      printButton_verde("TUESDAY ", terC[0], terC[1], terC[2], terC[3]); //botao terca
    } 
    else {
      printButton("TUESDAY ", terC[0], terC[1], terC[2], terC[3]); //botao terca
    }
    if (temp2quarta_dosagem_personalizada_1 == 3) {
      printButton_verde("WEDNESDAY", quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    } 
    else {
      printButton("WEDNESDAY", quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    }
    if (temp2quinta_dosagem_personalizada_1 == 4) {
      printButton_verde("THURSDAY", quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    } 
    else {
      printButton("THURSDAY", quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    }
    if (temp2sexta_dosagem_personalizada_1 == 5) {
      printButton_verde("FRIDAY", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else {
      printButton("FRIDAY", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
    if (temp2sabado_dosagem_personalizada_1 == 6) printButton_verde("SATURDAY", sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    else {
      printButton("SATURDAY", sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    }
    if (temp2domingo_dosagem_personalizada_1 == 7) printButton_verde("SUNDAY", domI[0], domI[1], domI[2], domI[3]); //botao sabado
    else {
      printButton("SUNDAY", domI[0], domI[1], domI[2], domI[3]); //botao sabado
    }

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    if (temp2hora_inicial_dosagem_personalizada_1 < 10) {
      myGLCD.printNumI(0, 70, 48);
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_1, 86, 48);
    } 
    else {
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_1, 70, 48);
    }

    if (temp2minuto_inicial_dosagem_personalizada_1 < 10) {
      myGLCD.printNumI(0, 120, 48);
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_1, 136, 48);
    } 
    else {
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_1, 120, 48);
    }
    if (temp2hora_final_dosagem_personalizada_1 < 10) {
      myGLCD.printNumI(0, 70 + deslocamento_botao_x, 48);
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_1, 86 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_1, 70 + deslocamento_botao_x, 48);
    }

    if (temp2minuto_final_dosagem_personalizada_1 < 10) {
      myGLCD.printNumI(0, 120 + deslocamento_botao_x, 48);
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_1, 136 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_1, 120 + deslocamento_botao_x, 48);
    }
  }
  if(dosadora_2_selecionada == true)
  {
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PUMP 2", 10, 198);
    myGLCD.print("SELECTED", 10, 218);

    if (temp2segunda_dosagem_personalizada_2 == 1) {
      printButton_verde("MONDAY", segU[0], segU[1], segU[2], segU[3]); //botao segunda
    } 
    else {
      printButton("MONDAY", segU[0], segU[1], segU[2], segU[3]); //botao segunda
    }
    if (temp2terca_dosagem_personalizada_2 == 2) {
      printButton_verde("TUESDAY ", terC[0], terC[1], terC[2], terC[3]); //botao terca
    } 
    else {
      printButton("TUESDAY ", terC[0], terC[1], terC[2], terC[3]); //botao terca
    }
    if (temp2quarta_dosagem_personalizada_2 == 3) {
      printButton_verde("WEDNESDAY", quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    } 
    else {
      printButton("WEDNESDAY", quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    }
    if (temp2quinta_dosagem_personalizada_2 == 4) {
      printButton_verde("THURSDAY", quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    } 
    else {
      printButton("THURSDAY", quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    }
    if (temp2sexta_dosagem_personalizada_2 == 5) {
      printButton_verde("FRIDAY", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else {
      printButton("FRIDAY", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
    if (temp2sabado_dosagem_personalizada_2 == 6) printButton_verde("SATURDAY", sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    else {
      printButton("SATURDAY", sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    }
    if (temp2domingo_dosagem_personalizada_2 == 7) printButton_verde("SUNDAY", domI[0], domI[1], domI[2], domI[3]); //botao sabado
    else {
      printButton("SUNDAY", domI[0], domI[1], domI[2], domI[3]); //botao sabado
    }

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    if (temp2hora_inicial_dosagem_personalizada_2 < 10) {
      myGLCD.printNumI(0, 70, 48);
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_2, 86, 48);
    } 
    else {
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_2, 70, 48);
    }

    if (temp2minuto_inicial_dosagem_personalizada_2 < 10) {
      myGLCD.printNumI(0, 120, 48);
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_2, 136, 48);
    } 
    else {
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_2, 120, 48);
    }
    if (temp2hora_final_dosagem_personalizada_2 < 10) {
      myGLCD.printNumI(0, 70 + deslocamento_botao_x, 48);
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_2, 86 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_2, 70 + deslocamento_botao_x, 48);
    }

    if (temp2minuto_final_dosagem_personalizada_2 < 10) {
      myGLCD.printNumI(0, 120 + deslocamento_botao_x, 48);
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_2, 136 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_2, 120 + deslocamento_botao_x, 48);
    }
  }
  if(dosadora_3_selecionada == true)
  {
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PUMP 3", 10, 198);
    myGLCD.print("SELECTED", 10, 218);

    if (temp2segunda_dosagem_personalizada_3 == 1) {
      printButton_verde("MONDAY", segU[0], segU[1], segU[2], segU[3]); //botao segunda
    } 
    else {
      printButton("MONDAY", segU[0], segU[1], segU[2], segU[3]); //botao segunda
    }
    if (temp2terca_dosagem_personalizada_3 == 2) {
      printButton_verde("TUESDAY ", terC[0], terC[1], terC[2], terC[3]); //botao terca
    } 
    else {
      printButton("TUESDAY ", terC[0], terC[1], terC[2], terC[3]); //botao terca
    }
    if (temp2quarta_dosagem_personalizada_3 == 3) {
      printButton_verde("WEDNESDAY", quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    } 
    else {
      printButton("WEDNESDAY", quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    }
    if (temp2quinta_dosagem_personalizada_3 == 4) {
      printButton_verde("THURSDAY", quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    } 
    else {
      printButton("THURSDAY", quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    }
    if (temp2sexta_dosagem_personalizada_3 == 5) {
      printButton_verde("FRIDAY", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else {
      printButton("FRIDAY", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
    if (temp2sabado_dosagem_personalizada_3 == 6) printButton_verde("SATURDAY", sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    else {
      printButton("SATURDAY", sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    }
    if (temp2domingo_dosagem_personalizada_3 == 7) printButton_verde("SUNDAY", domI[0], domI[1], domI[2], domI[3]); //botao sabado
    else {
      printButton("SUNDAY", domI[0], domI[1], domI[2], domI[3]); //botao sabado
    }

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    if (temp2hora_inicial_dosagem_personalizada_3 < 10) {
      myGLCD.printNumI(0, 70, 48);
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_3, 86, 48);
    } 
    else {
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_3, 70, 48);
    }

    if (temp2minuto_inicial_dosagem_personalizada_3 < 10) {
      myGLCD.printNumI(0, 120, 48);
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_3, 136, 48);
    } 
    else {
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_3, 120, 48);
    }
    if (temp2hora_final_dosagem_personalizada_3 < 10) {
      myGLCD.printNumI(0, 70 + deslocamento_botao_x, 48);
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_3, 86 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_3, 70 + deslocamento_botao_x, 48);
    }

    if (temp2minuto_final_dosagem_personalizada_3 < 10) {
      myGLCD.printNumI(0, 120 + deslocamento_botao_x, 48);
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_3, 136 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_3, 120 + deslocamento_botao_x, 48);
    }
  }
}

void solicitar_senha()  //---------------tela =30
{
  printHeader("ENTER THE PASSWORD");
  printButton("1", boT1[0], boT1[1], boT1[2], boT1[3],true);
  printButton("2", boT2[0], boT2[1], boT2[2], boT2[3],true);
  printButton("3", boT3[0], boT3[1], boT3[2], boT3[3],true);
  printButton("4", boT4[0], boT4[1], boT4[2], boT4[3],true);
  printButton("5", boT5[0], boT5[1], boT5[2], boT5[3],true);
  printButton("6", boT6[0], boT6[1], boT6[2], boT6[3],true);
  printButton("7", boT7[0], boT7[1], boT7[2], boT7[3],true);
  printButton("8", boT8[0], boT8[1], boT8[2], boT8[3],true);
  printButton("9", boT9[0], boT9[1], boT9[2], boT9[3],true);
  printButton("0", boT0[0], boT0[1], boT0[2], boT0[3],true);
  printButton("CLEAR", boTL[0], boTL[1], boTL[2], boTL[3],true);
  printButton("ENTER", boTE[0], boTE[1], boTE[2], boTE[3],true);
  printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);

}

void config_dosagem_personalizada_2(boolean refreshAll=false) // ----------tela =31
{
  if(refreshAll)
  {
    dose_dosadora_1_personalizada_temp2 = dose_dosadora_1_personalizada;
    dose_dosadora_2_personalizada_temp2 = dose_dosadora_2_personalizada;
    dose_dosadora_3_personalizada_temp2 = dose_dosadora_3_personalizada;
    quantidade_dose_dosadora_1_personalizada_temp2 = quantidade_dose_dosadora_1_personalizada;
    quantidade_dose_dosadora_2_personalizada_temp2 = quantidade_dose_dosadora_2_personalizada;
    quantidade_dose_dosadora_3_personalizada_temp2 = quantidade_dose_dosadora_3_personalizada;
    modo_personalizado_on_1_temp2 = modo_personalizado_on_1;
    modo_personalizado_on_2_temp2 = modo_personalizado_on_2;
    modo_personalizado_on_3_temp2 = modo_personalizado_on_3;
    modo_automatico_on_1_temp2 = modo_automatico_on_1;
    modo_automatico_on_2_temp2 = modo_automatico_on_2;
    modo_automatico_on_3_temp2 = modo_automatico_on_3;

    printHeader("PERSONALIZED DOSING CONFIGURATION");
    printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("MENU 1", menU[0], menU[1], menU[2], menU[3]);
    printButton("PREVIOUS", anT[0],anT[1], anT[2], anT[3]);
    printButton("SAVE", prOK[0],prOK[1], prOK[2], prOK[3]);
    printButton("+", minUT[0], minUT[1], minUT[2], minUT[3], true); //min up
    printButton("-", minDT[0], minDT[1], minDT[2], minDT[3], true); //min down
    printButton("+", durC[0], durC[1], durC[2], durC[3], true); //minuto mais
    printButton("-", durB[0], durB[1], durB[2], durB[3], true); //minuto menos
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.setFont(SmallFont);
    myGLCD.print("SELECT A", 10, 31);
    myGLCD.print("VOLUME ", 10, 55);
    myGLCD.print("(ML/DAY):", 10, 75);
    myGLCD.print("QUANTITY", 190, 46);
    myGLCD.print("DOSES NR.:", 190, 61);
  }

  if ((dosadora_1_selecionada == true) && (modo_personalizado == true ))
  { 
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_1_personalizada_temp2, 1, 100, 48);  
    if (quantidade_dose_dosadora_1_personalizada_temp2 < 10) 
    {
      myGLCD.printNumI(0, 275, 48);
      myGLCD.printNumI(quantidade_dose_dosadora_1_personalizada_temp2, 291, 48);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_1_personalizada_temp2, 275, 48);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PUMP 1 SELECTED", 125, 213);

    if (modo_personalizado_on_1_temp2 == 1) 
    {
      printButton_verde("ON", sexT[0], sexT[1], sexT[2], sexT[3]); 
    } 
    else 
    {
      printButton("OFF", sexT[0], sexT[1], sexT[2], sexT[3]); 
    }
  } 
  if ((dosadora_2_selecionada == true) && (modo_personalizado == true ))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_2_personalizada_temp2, 1, 100, 48);  
    if (quantidade_dose_dosadora_2_personalizada_temp2 < 10) 
    {
      myGLCD.printNumI(0, 275, 48);
      myGLCD.printNumI(quantidade_dose_dosadora_2_personalizada_temp2, 291, 48);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_2_personalizada_temp2, 275, 48);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PUMP 2 SELECTED", 125, 213);
    if (modo_personalizado_on_2_temp2 == 1) 
    {
      printButton_verde("ON", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else 
    {
      printButton("OFF", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
  }
  if ((dosadora_3_selecionada == true) && (modo_personalizado == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_3_personalizada_temp2, 1, 100, 48); 

    if (quantidade_dose_dosadora_3_personalizada_temp2 < 10) 
    {
      myGLCD.printNumI(0, 275, 48);
      myGLCD.printNumI(quantidade_dose_dosadora_3_personalizada_temp2, 291, 48);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_3_personalizada_temp2, 275, 48);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PUMP 3 SELECTED", 125, 213);
    if (modo_personalizado_on_3_temp2 == 1) 
    {
      printButton_verde("ON", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else 
    {
      printButton("OFF", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
  }
}

void rever_configuracao_dosadoras()//---------------------------------------------tela =32
{

  printHeader("CHANGE DOSING PUMP CONFIG.");

  printButton("AUTOMATIC", manU[0], manU[1], manU[2], manU[3]);
  printButton("PERSONALIZED", autO[0], autO[1], autO[2], autO[3]);
  printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
  printButton("MENU 1", menU[0], menU[1], menU[2], menU[3]);
  printButton("BACK", volT[0], volT[1], volT[2], volT[3]);
}

void rever_dosagem_automatica() // ----------tela =33
{

  printHeader("REVIEW AUTO DOSING CONF.");
  printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
  printButton("MENU 1", menU[0], menU[1], menU[2], menU[3]);
  printButton("BACK", volT[0], volT[1], volT[2], volT[3]);

  myGLCD.setColor(161, 127, 73);                    
  myGLCD.drawLine(1, 88, 319, 88);  
  myGLCD.drawLine(1, 158, 319, 158);
  myGLCD.drawLine(319, 15, 319, 239);

  setFont(SMALL, 255, 255, 255, 0, 0, 0);
  myGLCD.print("PUMP 1:", 100, 30);   
  myGLCD.print("INITIAL:", 10, 50);  
  myGLCD.print("FINAL:", 118, 50);
  myGLCD.print("NUMBER OF DOSES:", 10, 70);
  myGLCD.print("VOLUME:", 215, 50);    //Posição correta
  myGLCD.print(":", 90, 50);
  myGLCD.print(":", 180, 50);

  myGLCD.printNumF(dose_dosadora_1_automatica, 1, 275, 50); //Posição correta
  myGLCD.printNumI(quantidade_dose_dosadora_1_automatica, 170, 70);

  if(hora_inicial_dosagem_automatica_1 < 10)
  {
    myGLCD.printNumI(0, 72, 50);
    myGLCD.printNumI(hora_inicial_dosagem_automatica_1, 80, 50);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_automatica_1, 72, 50);
  }
  if(minuto_inicial_dosagem_automatica_1 < 10)
  {
    myGLCD.printNumI(0, 98, 50);
    myGLCD.printNumI(minuto_inicial_dosagem_automatica_1, 106, 50);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_automatica_1, 98, 50);
  }
  if(hora_final_dosagem_automatica_1 < 10)
  {
    myGLCD.printNumI(0, 165, 50);
    myGLCD.printNumI(hora_final_dosagem_automatica_1, 173, 50); 
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_automatica_1, 165, 50);
  }
  if(minuto_final_dosagem_automatica_1 < 10)
  {
    myGLCD.printNumI(0, 188, 50);
    myGLCD.printNumI(minuto_final_dosagem_automatica_1, 196, 50);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_automatica_1, 188, 50);
  }

  if (modo_automatico_on_1 == 1) 
  {
    printButton_verde("ON", 200, 65, 245, 85); 
  } 
  else 
  {
    printButton("ON", 200, 65, 245, 85); 
  }
  if (modo_automatico_on_1 == 0) 
  {
    printButton_verde("OFF", 250, 65, 295, 85); 
  } 
  else 
  {
    printButton("OFF", 250, 65, 295, 85); 
  }
  setFont(SMALL, 255, 255, 255, 0, 0, 0);    
  myGLCD.print("PUMP 2:", 100, 100);   
  myGLCD.print("INITAIL:", 10, 120);  
  myGLCD.print("FINAL:", 118, 120);
  myGLCD.print("NUMBER OF DOSES:", 10, 140);
  myGLCD.print("VOLUME:", 215, 120);    
  myGLCD.print(":", 90, 120);
  myGLCD.print(":", 180, 120);

  myGLCD.printNumF(dose_dosadora_2_automatica, 1, 275, 120); 
  myGLCD.printNumI(quantidade_dose_dosadora_2_automatica, 170, 140);
  if(hora_inicial_dosagem_automatica_2 < 10)
  {
    myGLCD.printNumI(0, 72, 120);
    myGLCD.printNumI(hora_inicial_dosagem_automatica_2, 80, 120);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_automatica_2, 72, 120);
  }
  if(minuto_inicial_dosagem_automatica_2 < 10)
  {
    myGLCD.printNumI(0, 98, 120);
    myGLCD.printNumI(minuto_inicial_dosagem_automatica_2, 106, 120);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_automatica_2, 98, 120);
  }
  if(hora_final_dosagem_automatica_2 < 10)
  {
    myGLCD.printNumI(0, 165, 120);
    myGLCD.printNumI(hora_final_dosagem_automatica_2, 173, 120); 
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_automatica_2, 165, 120);
  }
  if(minuto_final_dosagem_automatica_2 < 10)
  {
    myGLCD.printNumI(0, 188, 120);
    myGLCD.printNumI(minuto_final_dosagem_automatica_2, 196, 120);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_automatica_2, 188, 120);
  }

  if (modo_automatico_on_2 == 1) 
  {
    printButton_verde("ON", 200, 135, 245, 155); 
  } 
  else 
  {
    printButton("ON", 200, 135, 245, 155); 
  }
  if (modo_automatico_on_2 == 0) 
  {
    printButton_verde("OFF", 250, 135, 295, 155); 
  } 
  else 
  {
    printButton("OFF", 250, 135, 295, 155); 
  } 
  setFont(SMALL, 255, 255, 255, 0, 0, 0);    
  myGLCD.print("PUMP 3:", 100, 170);   
  myGLCD.print("INITIAL:", 10, 190);  
  myGLCD.print("FINAL:", 118, 190);
  myGLCD.print("NUMBER OF DOSES:", 10, 210);
  myGLCD.print("VOLUME:", 215, 190);    
  myGLCD.print(":", 90, 190);
  myGLCD.print(":", 180, 190);

  myGLCD.printNumF(dose_dosadora_3_automatica, 1, 275, 190); 
  myGLCD.printNumI(quantidade_dose_dosadora_3_automatica, 170, 210);
  if(hora_inicial_dosagem_automatica_3 < 10)
  {
    myGLCD.printNumI(0, 72, 190);
    myGLCD.printNumI(hora_inicial_dosagem_automatica_3, 80, 190);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_automatica_3, 72, 190);
  }
  if(minuto_inicial_dosagem_automatica_3 < 10)
  {
    myGLCD.printNumI(0, 98, 190);
    myGLCD.printNumI(minuto_inicial_dosagem_automatica_3, 106, 190);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_automatica_3, 98, 190);
  }
  if(hora_final_dosagem_automatica_3 < 10)
  {
    myGLCD.printNumI(0, 165, 190);
    myGLCD.printNumI(hora_final_dosagem_automatica_3, 173, 190); 
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_automatica_3, 165, 190);
  }
  if(minuto_final_dosagem_automatica_3 < 10)
  {
    myGLCD.printNumI(0, 188, 190);
    myGLCD.printNumI(minuto_final_dosagem_automatica_3, 196, 190);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_automatica_3, 188, 190);
  }

  if (modo_automatico_on_3 == 1) 
  {
    printButton_verde("ON", 200, 205, 245, 225); 
  } 
  else 
  {
    printButton("ON", 200, 205, 245, 225); 
  }
  if (modo_automatico_on_3 == 0) 
  {
    printButton_verde("OFF", 250, 205, 295, 225); 
  } 
  else 
  {
    printButton("OFF", 250, 205, 295, 225); 
  }     
}

void rever_dosagem_personalizada() // ------------------------------------------------------------------tela =34
{

  printHeader("REVIEW AUTOMATIC DOSING CONF.");
  printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
  printButton("MENU 1", menU[0], menU[1], menU[2], menU[3]);
  printButton("BACK", volT[0], volT[1], volT[2], volT[3]);

  myGLCD.setColor(161, 127, 73);                    
  myGLCD.drawLine(1, 88, 319, 88);  
  myGLCD.drawLine(1, 158, 319, 158);
  myGLCD.drawLine(319, 15, 319, 239);

  setFont(SMALL, 255, 255, 255, 0, 0, 0);
  myGLCD.print("PUMP 1:", 10, 30);   
  myGLCD.print("INITAIL:", 10, 50);  
  myGLCD.print("FINAL:", 118, 50);
  myGLCD.print("NUMBER OF DOSES:", 10, 70);
  myGLCD.print("VOLUME:", 215, 50);    //Posição correta
  myGLCD.print(":", 90, 50);
  myGLCD.print(":", 180, 50);

  myGLCD.printNumF(dose_dosadora_1_personalizada, 1, 275, 50); //Posição correta
  myGLCD.printNumI(quantidade_dose_dosadora_1_personalizada, 170, 70);

  if(hora_inicial_dosagem_personalizada_1 < 10)
  {
    myGLCD.printNumI(0, 72, 50);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_1, 80, 50);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_1, 72, 50);
  }
  if(minuto_inicial_dosagem_personalizada_1 < 10)
  {
    myGLCD.printNumI(0, 98, 50);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_1, 106, 50);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_1, 98, 50);
  }
  if(hora_final_dosagem_personalizada_1 < 10)
  {
    myGLCD.printNumI(0, 165, 50);
    myGLCD.printNumI(hora_final_dosagem_personalizada_1, 173, 50); 
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada_1, 165, 50);
  }
  if(minuto_final_dosagem_personalizada_1 < 10)
  {
    myGLCD.printNumI(0, 188, 50);
    myGLCD.printNumI(minuto_final_dosagem_personalizada_1, 196, 50);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada_1, 188, 50);
  }
  if(segunda_dosagem_personalizada_1 == 1)
  {
    printButton_verde("S", 110, 23, 130, 43);
  }
  else
  {
    printButton("S", 110, 23, 130, 43);
  }
  if(terca_dosagem_personalizada_1 == 2)
  {
    printButton_verde("T", 140, 23, 160, 43);
  }
  else
  {
    printButton("T", 140, 23, 160, 43);
  }
  if(quarta_dosagem_personalizada_1 == 3)
  {
    printButton_verde("Q", 170, 23, 190, 43);
  }
  else
  {
    printButton("Q", 170, 23, 190, 43);
  }    
  if(quinta_dosagem_personalizada_1 == 4)
  {
    printButton_verde("Q", 200, 23, 220, 43);
  }
  else
  {
    printButton("Q", 200, 23, 220, 43);
  }    
  if(sexta_dosagem_personalizada_1 == 5)
  {
    printButton_verde("S", 230, 23, 250, 43);
  }
  else
  {
    printButton("S", 230, 23, 250, 43);
  }
  if(sabado_dosagem_personalizada_1 == 6)
  {
    printButton_verde("S", 260, 23, 280, 43);
  }
  else
  {
    printButton("S", 260, 23, 280, 43);
  }
  if(domingo_dosagem_personalizada_1 == 7)
  {
    printButton_verde("D", 290, 23, 310, 43);
  }
  else
  {
    printButton("D", 290, 23, 310, 43);
  } 
  if (modo_personalizado_on_1 == 1) 
  {
    printButton_verde("ON", 200, 65, 245, 85); 
  } 
  else 
  {
    printButton("ON", 200, 65, 245, 85); 
  }
  if (modo_personalizado_on_1 == 0) 
  {
    printButton_verde("OFF", 250, 65, 295, 85); 
  } 
  else 
  {
    printButton("OFF", 250, 65, 295, 85); 
  }
  setFont(SMALL, 255, 255, 255, 0, 0, 0);    
  myGLCD.print("PUMP 2:", 10, 100);   
  myGLCD.print("INITIAL:", 10, 120);  
  myGLCD.print("FINAL:", 118, 120);
  myGLCD.print("NUMBER OF DOSES:", 10, 140);
  myGLCD.print("VOLUME:", 215, 120);    
  myGLCD.print(":", 90, 120);
  myGLCD.print(":", 180, 120);

  myGLCD.printNumF(dose_dosadora_2_personalizada, 1, 275, 120); 
  myGLCD.printNumI(quantidade_dose_dosadora_2_personalizada, 170, 140);
  if(hora_inicial_dosagem_personalizada_2 < 10)
  {
    myGLCD.printNumI(0, 72, 120);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_2, 80, 120);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_2, 72, 120);
  }
  if(minuto_inicial_dosagem_personalizada_2 < 10)
  {
    myGLCD.printNumI(0, 98, 120);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_2, 106, 120);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_2, 98, 120);
  }
  if(hora_final_dosagem_personalizada_2 < 10)
  {
    myGLCD.printNumI(0, 165, 120);
    myGLCD.printNumI(hora_final_dosagem_personalizada_2, 173, 120); 
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada_2, 165, 120);
  }
  if(minuto_final_dosagem_personalizada_2 < 10)
  {
    myGLCD.printNumI(0, 188, 120);
    myGLCD.printNumI(minuto_final_dosagem_personalizada_2, 196, 120);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada_2, 188, 120);
  }
  if(segunda_dosagem_personalizada_2 == 1)
  {
    printButton_verde("S", 110, 93, 130, 113);
  }
  else
  {
    printButton("S", 110, 93, 130, 113);
  }
  if(terca_dosagem_personalizada_2 == 2)
  {
    printButton_verde("T", 140, 93, 160, 113);
  }
  else
  {
    printButton("T", 140, 93, 160, 113);
  }
  if(quarta_dosagem_personalizada_2 == 3)
  {
    printButton_verde("Q", 170, 93, 190, 113);
  }
  else
  {
    printButton("Q", 170, 93, 190, 113);
  }    
  if(quinta_dosagem_personalizada_2 == 4)
  {
    printButton_verde("Q", 200, 93, 220, 113);
  }
  else
  {
    printButton("Q", 200, 93, 220, 113);
  }    
  if(sexta_dosagem_personalizada_2 == 5)
  {
    printButton_verde("S", 230, 93, 250, 113);
  }
  else
  {
    printButton("S", 230, 93, 250, 113);
  }
  if(sabado_dosagem_personalizada_2 == 6)
  {
    printButton_verde("S", 260, 93, 280, 113);
  }
  else
  {
    printButton("S", 260, 93, 280, 113);
  }
  if(domingo_dosagem_personalizada_2 == 7)
  {
    printButton_verde("D", 290, 93, 310, 113);
  }
  else
  {
    printButton("D", 290, 93, 310, 113);
  } 
  if (modo_personalizado_on_2 == 1) 
  {
    printButton_verde("ON", 200, 135, 245, 155); 
  } 
  else 
  {
    printButton("ON", 200, 135, 245, 155); 
  }
  if (modo_personalizado_on_2 == 0) 
  {
    printButton_verde("OFF", 250, 135, 295, 155); 
  } 
  else 
  {
    printButton("OFF", 250, 135, 295, 155); 
  } 
  setFont(SMALL, 255, 255, 255, 0, 0, 0);    
  myGLCD.print("PUMP 3:", 10, 170);   
  myGLCD.print("INITIAL:", 10, 190);  
  myGLCD.print("FINAL:", 118, 190);
  myGLCD.print("NUMBER OF DOSES:", 10, 210);
  myGLCD.print("VOLUME:", 215, 190);    
  myGLCD.print(":", 90, 190);
  myGLCD.print(":", 180, 190);

  myGLCD.printNumF(dose_dosadora_3_personalizada, 1, 275, 190); 
  myGLCD.printNumI(quantidade_dose_dosadora_3_personalizada, 170, 210);
  if(hora_inicial_dosagem_personalizada_3 < 10)
  {
    myGLCD.printNumI(0, 72, 190);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_3, 80, 190);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_3, 72, 190);
  }
  if(minuto_inicial_dosagem_personalizada_3 < 10)
  {
    myGLCD.printNumI(0, 98, 190);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_3, 106, 190);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_3, 98, 190);
  }
  if(hora_final_dosagem_personalizada_3 < 10)
  {
    myGLCD.printNumI(0, 165, 190);
    myGLCD.printNumI(hora_final_dosagem_personalizada_3, 173, 190); 
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada_3, 165, 190);
  }
  if(minuto_final_dosagem_personalizada_3 < 10)
  {
    myGLCD.printNumI(0, 188, 190);
    myGLCD.printNumI(minuto_final_dosagem_personalizada_3, 196, 190);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada_3, 188, 190);
  }
  if(segunda_dosagem_personalizada_3 == 1)
  {
    printButton_verde("S", 110, 163, 130, 183);
  }
  else
  {
    printButton("S", 110, 163, 130, 183);
  }
  if(terca_dosagem_personalizada_3 == 2)
  {
    printButton_verde("T", 140, 163, 160, 183);
  }
  else
  {
    printButton("T", 140, 163, 160, 183);
  }
  if(quarta_dosagem_personalizada_3 == 3)
  {
    printButton_verde("Q", 170, 163, 190, 183);
  }
  else
  {
    printButton("Q", 170, 163, 190, 183);
  }    
  if(quinta_dosagem_personalizada_3 == 4)
  {
    printButton_verde("Q", 200, 163, 220, 183);
  }
  else
  {
    printButton("Q", 200, 163, 220, 183);
  }    
  if(sexta_dosagem_personalizada_3 == 5)
  {
    printButton_verde("S", 230, 163, 250, 183);
  }
  else
  {
    printButton("S", 230, 163, 250, 183);
  }
  if(sabado_dosagem_personalizada_3 == 6)
  {
    printButton_verde("S", 260, 163, 280, 183);
  }
  else
  {
    printButton("S", 260, 163, 280, 183);
  }
  if(domingo_dosagem_personalizada_3 == 7)
  {
    printButton_verde("D", 290, 163, 310, 183);
  }
  else
  {
    printButton("D", 290, 163, 310, 183);
  } 
  if (modo_personalizado_on_3 == 1) 
  {
    printButton_verde("ON", 200, 205, 245, 225); 
  } 
  else 
  {
    printButton("ON", 200, 205, 245, 225); 
  }
  if (modo_personalizado_on_3 == 0) 
  {
    printButton_verde("OFF", 250, 205, 295, 225); 
  } 
  else 
  {
    printButton("OFF", 250, 205, 295, 225); 
  }     
}

//---------------------------------------------Dosing pump deactivation--------------------------------tela =35 ----------
void desativar_dosadoras(boolean refreshAll = false)
{
  if(refreshAll == true)
  {
    if((modo_personalizado_on_1 == 1) || (modo_automatico_on_1 == 1))
    {
      ativar_desativar_1 = 1;
    }
    else
    {
      ativar_desativar_1 = 0;
    }
    if((modo_personalizado_on_2 == 1) || (modo_automatico_on_2 == 1))
    {
      ativar_desativar_2 = 1;
    }
    else
    {
      ativar_desativar_2 = 0;
    }
    if((modo_personalizado_on_3 == 1) || (modo_automatico_on_3 == 1))
    {
      ativar_desativar_3 = 1;
    }
    else
    {
      ativar_desativar_3 = 0;
    }
    printHeader("DEACTIVATE PUMP");
    printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("MENU 1", menU[0], menU[1], menU[2], menU[3]);
    printButton("SAVE", salV[0], salV[1], salV[2], salV[3]);
    printButton("BACK", volT[0], volT[1], volT[2], volT[3]);

    setFont(SMALL, 255, 255, 255, 0, 0, 0); 
    myGLCD.print("PUMP 1:", 117, 30);
    myGLCD.print("PUMP 2:", 120, 100);
    myGLCD.print("PUMP 3:", 120, 170); 
    setFont(SMALL, 255, 0, 0, 0, 0, 0); 
    myGLCD.print("USE THIS", 230, 60);
    myGLCD.print("FUNCAO", 230, 75);
    myGLCD.print("APENAS PARA", 230, 90);
    myGLCD.print("DEACTIVATE", 230, 105);
    myGLCD.print("OS MODOS", 230, 120); 
    myGLCD.print("DE DOSAGEM.", 230, 135); 
  }
  if (ativar_desativar_1 == 1)
  {
    printButton_verde("ACTIVATED", 100, 45, 220, 85);
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect (3, 26, 117, 43);
    myGLCD.fillRect (3, 45, 95, 61);
    myGLCD.fillRect (3, 60, 95, 76);
    myGLCD.fillRect (3, 75, 95, 91);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("UM DOS MODOS", 10, 30);
    myGLCD.print("DE DOSAGEM", 10, 45);
    myGLCD.print("ESTA:", 10, 60); 
  } 
  else 
  {
    printButton("DESATIVADOS", 100, 45, 220, 85);
    setFont(SMALL, 255, 255, 0, 0, 0, 0); 
    myGLCD.print("AMBOS OS MODOS", 3, 30); 
    myGLCD.print("DE DOSAGEM  ", 3, 45);
    myGLCD.print("ESTAO OU", 3, 60);
    myGLCD.print("SERAO:", 3, 75); 
  }
  if (ativar_desativar_2 == 1)
  {
    printButton_verde("ATIVADO", 100, 115, 220, 155);
    myGLCD.setColor(0, 0, 0); 
    myGLCD.fillRect (3, 96, 117, 113);
    myGLCD.fillRect (3, 115, 95, 131);
    myGLCD.fillRect (3, 130, 95, 146);
    myGLCD.fillRect (3, 145, 95, 161); 
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("UM DOS MODOS", 10, 100);
    myGLCD.print("DE DOSAGEM", 10, 115);
    myGLCD.print("ESTA:", 10, 130); 
  } 
  else 
  {
    printButton("DEACTIVATED", 100, 115, 220, 155); 
    setFont(SMALL, 255, 255, 0, 0, 0, 0); 
    myGLCD.print("AMBOS OS MODOS", 3, 100); 
    myGLCD.print("DE DOSAGEM  ", 3, 115);
    myGLCD.print("ESTAO OU", 3, 130);
    myGLCD.print("SERAO:", 3, 145);
  }
  if (ativar_desativar_3 == 1)
  {
    printButton_verde("ACTIVATED", 100, 185, 220, 225); 
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect (3, 166, 120, 183);
    myGLCD.fillRect (3, 185, 95, 201);
    myGLCD.fillRect (3, 200, 95, 216);
    myGLCD.fillRect (3, 215, 95, 231);
    setFont(SMALL, 255, 255, 255, 0, 0, 0); 
    myGLCD.print("UM DOS MODOS", 10, 170);
    myGLCD.print("DE DOSAGEM", 10, 185);
    myGLCD.print("ESTA:", 10, 200); 
  } 
  else 
  {
    printButton("DESATIVADOS", 100, 185, 220, 225);
    setFont(SMALL, 255, 255, 0, 0, 0, 0); 
    myGLCD.print("AMBOS OS MODOS", 3, 170); 
    myGLCD.print("DE DOSAGEM  ", 3, 185);
    myGLCD.print("ESTAO OU", 3, 200);
    myGLCD.print("SERAO:", 3, 215);
  }
}

//--------------------------------------------- Night light intensity min. and max. -------------------------------- tela =36 
void luz_noturna(boolean refreshAll=false)
{

  if (refreshAll)
  {
    tMaxI = MaxI;
    tMinI = MinI;

    printHeader("NIGHT LIGHT   255 = 100 %");

    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("MAX INTENSITY:", 90, 70);
    myGLCD.print("ILUMINACAO MINIMA:", 90, 170);
    myGLCD.print("LUA CHEIA:", 120, 20);
    myGLCD.print("LUA NOVA:", 125, 120);

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //Lua cheia menos
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //Lua cheia mais
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //Lua nova menos
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //Lua nova mais

    printButton("SAVE", prOK[0], prOK[1], prOK[2], prOK[3]);
    printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("MENU 2", menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0); 
  myGLCD.printNumI(tMaxI, 135, 40);
  myGLCD.printNumI(tMinI, 135, 140);
}

//--------------------------------------------- Menu 2 -------------------------------- tela =37
void menuScreen_2()
{

  printHeader("MENU 2");
  printButton("NIGHT LIGHT", tanD[0], tanD[1], tanD[2], tanD[3]); // 1º botaão, 1ª coluna
  printButton("TIMERS", tesT[0], tesT[1], tesT[2], tesT[3]); // 2º botão, 1ª coluna
  //  printButton("", temC[0], temC[1], temC[2], temC[3]); // 3º botão, 1ª coluna
  //  printButton("", graF[0], graF[1], graF[2], graF[3]); // 4º botão, 1ª coluna
  //  printButton("", ledW[0], ledW[1], ledW[2], ledW[3]); // 1º botão, 2ª coluna
  //  printButton("", tpaA[0], tpaA[1], tpaA[2], tpaA[3]); // 2º botão, 2ª coluna
  //  printButton("", dosA[0], dosA[1], dosA[2], dosA[3]); // 3º botão, 2ª coluna
  //  printButton("", wavM[0], wavM[1], wavM[2], wavM[3]); // 4º botão, 2ª coluna
  printButton("MENU 1", menU[0], menU[1], menU[2], menU[3]);
  printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]);
}

//--------------------------------------------- Timers -------------------------------- tela =38
void TimerScreen()
{ 

  printHeader("SELECT A TIMER");

  if (temporizador_1_ativado == 1) 
  {
    printButton_verde("T 1",7, 22, 56, 50);     // Timer 1 
  }
  else 
  {
    printButton("T 1",7, 22, 56, 50);     // Timer 1 
  }      
  if (temporizador_2_ativado == 1) 
  {
    printButton_verde("T 2",71, 22, 120, 50);     // Timer 2 
  }
  else 
  {
    printButton("T 2",71, 22, 120, 50);     // Timer 2 
  }     
  if (temporizador_3_ativado == 1) 
  {
    printButton_verde("T 3",135, 22, 184, 50);     // Timer 3 
  }
  else 
  {
    printButton("T 3",135, 22, 184, 50);     // Timer 3 
  }    
  if (temporizador_4_ativado == 1) 
  {
    printButton_verde("T 4",199, 22, 248, 50);     // Timer 4 
  }
  else 
  {
    printButton("T 4",199, 22, 248, 50);     // Timer 4 
  }        
  if (temporizador_5_ativado == 1) 
  {
    printButton_verde("T 5",263, 22, 312, 50);     // Timer 5 
  }
  else 
  {
    printButton("T 5",263, 22, 312, 50);     // Timer 5
  } 

  printButton_verde("ON",7, 55, 56, 97);      // Botão ON 1 
  printButton_verde("ON",71, 55, 120, 97);    // Botão ON 2
  printButton_verde("ON",135, 55, 184, 97);   // Botão ON 3
  printButton_verde("ON",199, 55, 248, 97);   // Botão ON 4
  printButton_verde("ON",263, 55, 312, 97);   // Botão ON 5

  myGLCD.setColor(255, 255, 255);  // Retângulos ao redor dos horários
  myGLCD.drawRoundRect(7, 102, 56, 144);      // Botão ON 1 
  myGLCD.drawRoundRect(71, 102, 120, 144);    // Botão ON 2 
  myGLCD.drawRoundRect(135, 102, 184, 144);   // Botão ON 3 
  myGLCD.drawRoundRect(199, 102, 248, 144);   // Botão ON 4 
  myGLCD.drawRoundRect(263, 102, 312, 144);   // Botão ON 5  

  printButton_vermelho("OFF",8, 149, 55, 191);      // Botão OFF 1 
  printButton_vermelho("OFF",72, 149, 119, 191);    // Botão OFF 2 
  printButton_vermelho("OFF",136, 149, 183, 191);   // Botão OFF 3 
  printButton_vermelho("OFF",200, 149, 247, 191);   // Botão OFF 4 
  printButton_vermelho("OFF",264, 149, 311, 191);   // Botão OFF 5 

  myGLCD.setColor(255, 255, 255);  // Retângulos ao redor dos horários
  myGLCD.drawRoundRect(7, 196, 56, 238);     // Botão OFF 1 
  myGLCD.drawRoundRect(71, 196, 120, 238);   // Botão OFF 2 
  myGLCD.drawRoundRect(135, 196, 184, 238);  // Botão OFF 3 
  myGLCD.drawRoundRect(199, 196, 248, 238);  // Botão OFF 4 
  myGLCD.drawRoundRect(263, 196, 312, 238);  // Botão OFF 5

  myGLCD.setBackColor(0, 0, 0);

  if (on1_hora < 10) // Timer 1
  { 
    myGLCD.print("0",12, 117); 
    myGLCD.printNumI(on1_hora,21,117);
  }
  else
  {
    myGLCD.printNumI(on1_hora, 12, 117);
  }
  myGLCD.print(":", 29, 117); 

  if (on1_minuto < 10)
  { 
    myGLCD.print("0", 37, 117);
    myGLCD.printNumI(on1_minuto, 46, 117);
  } 
  else 
  { 
    myGLCD.printNumI(on1_minuto, 37,117);
  }      

  if (on2_hora < 10) // Timer 2
  { 
    myGLCD.print("0", 76, 117);
    myGLCD.printNumI(on2_hora ,85, 117);
  }
  else
  {
    myGLCD.printNumI(on2_hora, 76, 117);
  }

  myGLCD.print(":", 93, 117);    

  if (on2_minuto < 10)
  { 
    myGLCD.print("0",101, 117);  
    myGLCD.printNumI(on2_minuto, 110, 117);
  } 
  else 
  { 
    myGLCD.printNumI(on2_minuto,101, 117);
  } 

  if (on3_hora <10) // Timer 3
  { 
    myGLCD.print("0",140, 117);   
    myGLCD.printNumI(on3_hora,149, 117);
  }
  else
  {
    myGLCD.printNumI(on3_hora, 140, 117);
  } 

  myGLCD.print(":",157, 117);          

  if (on3_minuto < 10)
  { 
    myGLCD.print("0",165, 117);  
    myGLCD.printNumI(on3_minuto, 174, 117);
  } 
  else { 
    myGLCD.printNumI(on3_minuto ,165, 117);
  } 

  if (on4_hora < 10) // Timer 4
  { 
    myGLCD.print("0",204, 117); 
    myGLCD.printNumI(on4_hora,213, 117);
  }
  else{
    myGLCD.printNumI(on4_hora,204, 117);
  }

  myGLCD.print(":",221, 117);         

  if (on4_minuto < 10)
  { 
    myGLCD.print("0",229, 117);  
    myGLCD.printNumI(on4_minuto, 238, 117);
  } 
  else 
  { 
    myGLCD.printNumI(on4_minuto, 229, 117);
  } 

  if (on5_hora < 10) // Timer 5
  { 
    myGLCD.print("0",268, 117);  
    myGLCD.printNumI(on5_hora, 277, 117);
  }
  else
  {
    myGLCD.printNumI(on5_hora, 268, 117);
  } 

  myGLCD.print(":",285, 117);          

  if (on5_minuto < 10)
  { 
    myGLCD.print("0", 293, 117); 
    myGLCD.printNumI(on5_minuto, 302, 117);
  } 
  else 
  { 
    myGLCD.printNumI(on5_minuto, 293, 117);
  } 

  if (off1_hora < 10) // Timer 1
  { 
    myGLCD.print("0",12, 211); 
    myGLCD.printNumI(off1_hora, 21, 211);
  }
  else
  {
    myGLCD.printNumI(off1_hora, 12, 211);
  }

  myGLCD.print(":", 29, 210); 

  if (off1_minuto < 10)
  { 
    myGLCD.print("0", 37, 211);
    myGLCD.printNumI(off1_minuto, 46, 211);
  } 
  else 
  { 
    myGLCD.printNumI(off1_minuto, 37,211);
  }      

  if (off2_hora < 10) // Timer 2
  { 
    myGLCD.print("0", 76, 211);
    myGLCD.printNumI(off2_hora , 85, 211);
  }
  else
  {
    myGLCD.printNumI(off2_hora, 76, 211);
  }

  myGLCD.print(":", 93, 211);    

  if (off2_minuto < 10)
  { 
    myGLCD.print("0",101, 211);  
    myGLCD.printNumI(off2_minuto, 110, 211);
  } 
  else 
  { 
    myGLCD.printNumI(off2_minuto,101, 211);
  } 

  if (off3_hora <10) // Timer 3
  { 
    myGLCD.print("0", 140, 211);   
    myGLCD.printNumI(off3_hora, 149, 211);
  }
  else
  {
    myGLCD.printNumI(off3_hora, 140, 211);
  } 

  myGLCD.print(":", 157, 211);          

  if (off3_minuto < 10)
  { 
    myGLCD.print("0", 165, 211);  
    myGLCD.printNumI(off3_minuto, 174, 211);
  } 
  else 
  { 
    myGLCD.printNumI(off3_minuto, 165, 211);
  } 

  if (off4_hora < 10) // Timer 4
  { 
    myGLCD.print("0", 204, 211); 
    myGLCD.printNumI(off4_hora, 213, 211);
  }
  else
  {
    myGLCD.printNumI(off4_hora, 204, 211);
  }

  myGLCD.print(":", 221, 211);         

  if (off4_minuto < 10)
  { 
    myGLCD.print("0", 229, 211);  
    myGLCD.printNumI(off4_minuto, 238, 211);
  } 
  else 
  { 
    myGLCD.printNumI(off4_minuto, 229, 211);
  } 

  if (off5_hora < 10) // Timer 5
  { 
    myGLCD.print("0", 268, 211);  
    myGLCD.printNumI(off5_hora, 277, 211);
  }
  else
  {
    myGLCD.printNumI(off5_hora, 268, 211);
  } 

  myGLCD.print(":", 285, 211);          

  if (off5_minuto < 10)
  { 
    myGLCD.print("0", 293, 211); 
    myGLCD.printNumI(off5_minuto, 302, 211);
  } 
  else { 
    myGLCD.printNumI(off5_minuto, 293, 211);
  }

  printButton("MENU 2", menU[0], menU[1], menU[2], menU[3]); //Volta ao menu 1.
  printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]); // Volta ao início.
} 
//--------------------------------------------- Configurar timers -------------------------------- tela =39
void config_timer(boolean refreshAll=false)
{
  if( refreshAll == true)
  {
    on1_minuto_temp2 = on1_minuto;
    on1_hora_temp2 = on1_hora;
    on2_minuto_temp2 = on2_minuto;
    on2_hora_temp2 = on2_hora;
    on3_minuto_temp2 = on3_minuto;
    on3_hora_temp2 = on3_hora;
    on4_minuto_temp2 = on4_minuto;
    on4_hora_temp2 = on4_hora;
    on5_minuto_temp2 = on5_minuto;
    on5_hora_temp2 = on5_hora ;
    off1_minuto_temp2 = off1_minuto;
    off1_hora_temp2 = off1_hora;
    off2_minuto_temp2 = off2_minuto;
    off2_hora_temp2 = off2_hora;
    off3_minuto_temp2 = off3_minuto;
    off3_hora_temp2 = off3_hora;
    off4_minuto_temp2 = off4_minuto;
    off4_hora_temp2 = off4_hora;
    off5_minuto_temp2 = off5_minuto;
    off5_hora_temp2 = off5_hora;
    temporizador_1_ativado_temp2 = temporizador_1_ativado;
    temporizador_2_ativado_temp2 = temporizador_2_ativado;
    temporizador_3_ativado_temp2 = temporizador_3_ativado;
    temporizador_4_ativado_temp2 = temporizador_4_ativado;
    temporizador_5_ativado_temp2 = temporizador_5_ativado;

    if(temporizador_1 == true)
    {
      printHeader("CONFIGURAR TIMER 1");
    }
    else if(temporizador_2 == true)
    {
      printHeader("CONFIGURAR TIMER 2");
    }
    else  if(temporizador_3 == true)
    {
      printHeader("CONFIGURAR TIMER 3");
    }
    else if(temporizador_4 == true)
    {
      printHeader("CONFIGURAR TIMER 4");
    }
    else if(temporizador_5 == true)
    {
      printHeader("CONFIGURAR TIMER 5");
    }

    printButton_verde("LIGAR TIMER", 8, 17, 142, 34);
    printButton_vermelho("DESLIGAR TIMER", 173, 17, 312, 34);
    printButton("+", 21, 45, 65, 88, true);    // Botão para cima
    printButton("+", 89, 45, 133, 88, true);    // Botão para cima
    printButton("-", 21, 135, 65, 178, true); // Botão para baixo
    printButton("-", 89, 135, 133, 178, true); // Botão para baixo

    printButton("+", 187, 45, 231, 88, true);    // Botão para cima
    printButton("+", 255, 45, 299, 88, true);    // Botão para cima
    printButton("-", 187, 135, 231, 178, true); // Botão para baixo
    printButton("-", 255, 135, 299, 178, true); // Botão para baixo

    printButton("MENU 2", menU[0], menU[1], menU[2], menU[3]); // Volta ao menu 2.
    printButton("HOME", iniC[0], iniC[1], iniC[2], iniC[3]); // Volta ao início.
    printButton("BACK", volT[0], volT[1], volT[2], volT[3]); // Volta ao menu selecionar timer.
    printButton("SAVE", salV[0], salV[1], salV[2], salV[3]); // Salva as modificações.

    setFont(LARGE, 255, 255, 255, 0, 0, 0);          
    myGLCD.print(":",70, 103);
    myGLCD.print(":",236, 103);
  }
  setFont(LARGE, 255, 255, 255, 0, 0, 0);

  if(temporizador_1 == true)
  {
    if (on1_hora_temp2 < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(on1_hora_temp2, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(on1_hora_temp2, 27, 100);
    }

    if (on1_minuto_temp2 < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(on1_minuto_temp2, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(on1_minuto_temp2, 95, 100);
    }

    if (off1_hora_temp2 < 10)
    {
      myGLCD.print("0",193, 100);            
      myGLCD.printNumI(off1_hora_temp2, 210, 100);
    } 
    else 
    {
      myGLCD.printNumI(off1_hora_temp2, 193, 100);
    }

    if (off1_minuto_temp2 < 10)
    {
      myGLCD.print("0",262, 100); 
      myGLCD.printNumI(off1_minuto_temp2, 279, 100);
    } 
    else 
    {
      myGLCD.printNumI(off1_minuto_temp2, 262, 100);
    }
    if (temporizador_1_ativado_temp2 == 1) 
    {
      printButton_verde("ATIVADO", domI[0]-20, domI[1], domI[2]+20, domI[3]); // Ativado 120, 193, 200, 233
    }
    else 
    {
      printButton("DESATIVADO", domI[0]-20, domI[1], domI[2]+20, domI[3]); // Desativado
    } 
  }
  else if(temporizador_2 == true)
  {
    if (on2_hora_temp2 < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(on2_hora_temp2, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(on2_hora_temp2, 27, 100);
    }

    if (on2_minuto_temp2 < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(on2_minuto_temp2, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(on2_minuto_temp2, 95, 100);
    }

    if (off2_hora_temp2 < 10)
    {
      myGLCD.print("0",193, 100);            
      myGLCD.printNumI(off2_hora_temp2, 210, 100);
    } 
    else 
    {
      myGLCD.printNumI(off2_hora_temp2, 193, 100);
    }

    if (off2_minuto_temp2 < 10)
    {
      myGLCD.print("0",262, 100); 
      myGLCD.printNumI(off2_minuto_temp2, 279, 100);
    } 
    else 
    {
      myGLCD.printNumI(off2_minuto_temp2, 262, 100);
    } 
    if (temporizador_2_ativado_temp2 == 1) 
    {
      printButton_verde("ATIVADO", domI[0]-20, domI[1], domI[2]+20, domI[3]); // Ativado
    }
    else 
    {
      printButton("DESATIVADO", domI[0]-20, domI[1], domI[2]+20, domI[3]); // Desativado
    }
  }
  else  if(temporizador_3 == true)
  {
    if (on3_hora_temp2 < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(on3_hora_temp2, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(on3_hora_temp2, 27, 100);
    }

    if (on3_minuto_temp2 < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(on3_minuto_temp2, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(on3_minuto_temp2, 95, 100);
    }

    if (off3_hora_temp2 < 10)
    {
      myGLCD.print("0",193, 100);            
      myGLCD.printNumI(off3_hora_temp2, 210, 100);
    } 
    else 
    {
      myGLCD.printNumI(off3_hora_temp2, 193, 100);
    }

    if (off3_minuto_temp2 < 10)
    {
      myGLCD.print("0",262, 100); 
      myGLCD.printNumI(off3_minuto_temp2, 279, 100);
    } 
    else 
    {
      myGLCD.printNumI(off3_minuto_temp2, 262, 100);
    } 
    if (temporizador_3_ativado_temp2 == 1) 
    {
      printButton_verde("ATIVADO", domI[0]-20, domI[1], domI[2]+20, domI[3]); // Ativado
    }
    else 
    {
      printButton("DESATIVADO", domI[0]-20, domI[1], domI[2]+20, domI[3]); // Desativado
    }
  }
  else if(temporizador_4 == true)
  {
    if (on4_hora_temp2 < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(on4_hora_temp2, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(on4_hora_temp2, 27, 100);
    }

    if (on4_minuto_temp2 < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(on4_minuto_temp2, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(on4_minuto_temp2, 95, 100);
    }

    if (off4_hora_temp2 < 10)
    {
      myGLCD.print("0",193, 100);            
      myGLCD.printNumI(off4_hora_temp2, 210, 100);
    } 
    else 
    {
      myGLCD.printNumI(off4_hora_temp2, 193, 100);
    }

    if (off4_minuto_temp2 < 10)
    {
      myGLCD.print("0",262, 100); 
      myGLCD.printNumI(off4_minuto_temp2, 279, 100);
    } 
    else 
    {
      myGLCD.printNumI(off4_minuto_temp2, 262, 100);
    }
    if (temporizador_4_ativado_temp2 == 1) 
    {
      printButton_verde("ATIVADO", domI[0]-20, domI[1], domI[2]+20, domI[3]); // Ativado
    }
    else 
    {
      printButton("DESATIVADO", domI[0]-20, domI[1], domI[2]+20, domI[3]); // Desativado
    }
  } 
  if(temporizador_5 == true)
  {
    if (on5_hora_temp2 < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(on5_hora_temp2, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(on5_hora_temp2, 27, 100);
    }

    if (on5_minuto_temp2 < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(on5_minuto_temp2, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(on5_minuto_temp2, 95, 100);
    }

    if (off5_hora_temp2 < 10)
    {
      myGLCD.print("0",193, 100);            
      myGLCD.printNumI(off5_hora_temp2, 210, 100);
    } 
    else 
    {
      myGLCD.printNumI(off5_hora_temp2, 193, 100);
    }

    if (off5_minuto_temp2 < 10)
    {
      myGLCD.print("0",262, 100); 
      myGLCD.printNumI(off5_minuto_temp2, 279, 100);
    } 
    else 
    {
      myGLCD.printNumI(off5_minuto_temp2, 262, 100);
    }  
    if (temporizador_5_ativado_temp2 == 1) 
    {
      printButton_verde("ATIVADO", domI[0]-20, domI[1], domI[2]+20, domI[3]); // Ativado
    }
    else 
    {
      printButton("DESATIVADO", domI[0]-20, domI[1], domI[2]+20, domI[3]); // Desativado
    }
  }
}







