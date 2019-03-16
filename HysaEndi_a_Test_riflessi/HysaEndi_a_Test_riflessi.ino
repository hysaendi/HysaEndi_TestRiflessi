int  ledBlu; //led primotest
int buzzer; //secondo test
int rgb_Rosso; //led che cambia colore
int rgb_Verde; 
int tempoTestIn;  //tempo prova led blu
int tempoTestBuzz;  //tempo prova buzzer
int bottone;//bottone per esecuzione primo test
int statoBottone; //stato del bottone: HIGH o LOW
int tempoTestTot;



void setup() {
  // put your setup code here, to run once:
  bottone = 3;
  ledBlu = 4;
  buzzer = 5;
  rgb_Rosso = 8;
  rgb_Verde = 9;
  
  
 pinMode (bottone,INPUT);
 pinMode (ledBlu, OUTPUT);
 pinMode (buzzer, OUTPUT);
 pinMode (rgb_Rosso, OUTPUT);
 pinMode (rgb_Verde, OUTPUT);
  
  

}  

void loop() {
  // put your main code here, to run repeatedly:
   premerePulsante();  //il programma parte con la pressione del bottone
   tempoTestIn = esecuzioneTest (ledBlu, "Lasso di tempo riguardante il test visivo:");  //restituisce il tempo relativo al test del led Blu
   tempoTestBuzz = esecuzioneTest (buzzer, "Lasso di tempo riguardante il test uditivo:"); //restituisce il tempo relativo al test del Buzzer
   verificaTest (tempoTestIn,tempoTestBuzz,rgb_Verde,rgb_Rosso);  //controlla i tempi e accende il led a seconda del completamento corretto dei test
  
   

}

void premerePulsante()
{ bool btnPremuto = false;
  statoBottone = digitalRead (bottone); //variabile di appoggio
  while (!btnPremuto)
  {
    if (statoBottone == HIGH)
    {
      btnPremuto = true;
    }
    else
    {
      btnPremuto = false;
    }
  }
  
}

int esecuzioneTest (int oggetto, String messaggio)  //oggetto indico i led o il buzzer
{
  
  delay (random(500,8000));
  digitalWrite (oggetto,HIGH);
  tempoTestIn = millis(); //restituisce il tempo trascorso fino a quando non premo il pulsante
  digitalWrite (oggetto,LOW);
  premerePulsante();
  delay (random(500,8000));
  digitalWrite (oggetto,HIGH);
  tempoTestBuzz = millis();
  tempoTestTot = tempoTestIn + tempoTestBuzz;
  Serial.println (messaggio + String(tempoTestTot));
}

void verificaTest (int tempoTestIn, int tempoTestBuzz , int testSuperato, int testNonSuperato)
{
  //con test superato e non superato intendo di che colore il led rgb si dovrà colorare ( verde = test superato / rosso = test non superato)
  if (tempoTestIn > 250 && tempoTestBuzz > 250)
  {
    digitalWrite (testNonSuperato,HIGH);
  }
  else
  {
    digitalWrite (testSuperato,HIGH);
  }
  digitalWrite (testSuperato,LOW);  //spengo i 2 led rgb
  digitalWrite (testNonSuperato,LOW);
}
