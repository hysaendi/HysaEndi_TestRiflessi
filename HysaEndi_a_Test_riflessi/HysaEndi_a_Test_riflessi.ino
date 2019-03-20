int  ledBlu; //led primotest
int buzzer; //secondo test
int rgb_Rosso; //led che cambia colore
int rgb_Verde; 
int tempoTestIn;  //tempo prova led blu
int tempoTestBuzz;  //tempo prova buzzer
int bottone;//bottone per esecuzione primo test
int statoBottone; //stato del bottone: HIGH o LOW




void setup() {
  // put your setup code here, to run once:
  bottone = 3;
  ledBlu = 4;
  buzzer = 5;
  rgb_Rosso = 9;
  rgb_Verde = 8;
  
  
 pinMode (bottone,INPUT);
 pinMode (ledBlu, OUTPUT);
 pinMode (buzzer, OUTPUT);
 pinMode (rgb_Rosso, OUTPUT);
 pinMode (rgb_Verde, OUTPUT);
 Serial.begin(9600);
  
  

}  

void loop() {
  // put your main code here, to run repeatedly:
   Serial.println ("PER INIZIARE, PREMI IL PULSANTE");
   premerePulsante();  //il programma parte con la pressione del bottone
   tempoTestIn = esecuzioneTest (ledBlu, "Lasso di tempo riguardante il test visivo (INPUT IN MS):");  //restituisce il tempo relativo al test del led Blu
   tempoTestBuzz = esecuzioneTest (buzzer, "Lasso di tempo riguardante il test uditivo (INPUT IN MS) :"); //restituisce il tempo relativo al test del Buzzer
   verificaTest (tempoTestIn,tempoTestBuzz);  //controlla i tempi e accende il led a seconda del completamento corretto dei test
   Serial.println ("FINE TEST");
}

void premerePulsante()
{ 
  bool btnPremuto = false;
 // statoBottone = digitalRead (bottone)
  while (!btnPremuto)
  {
    if (digitalRead (bottone) == HIGH)
    {
       btnPremuto = true;
    }
    
  }
}
    
int esecuzioneTest (int oggetto, String messaggio)  
{
  int tempoUno;
  int tempoTestTot;
  delay (random(500,8000));
  digitalWrite (oggetto,HIGH);
  tempoUno = millis(); //restituisce il tempo trascorso fino a quando non premo il pulsante
  premerePulsante();
  digitalWrite (oggetto,LOW);
  int tempoDue = millis();
  tempoTestTot = tempoDue - tempoUno ; 
  Serial.println (messaggio + String(tempoTestTot));
  
}

void verificaTest (int tempoTestIn, int tempoTestBuzz)
{
  //con test superato e non superato intendo di che colore il led rgb si dovrà colorare ( verde = test superato / rosso = test non superato)
  if (tempoTestIn >= 500 || tempoTestBuzz >= 500)
  {  
    digitalWrite (rgb_Rosso,HIGH);
  }
  else 
  {    
    digitalWrite (rgb_Verde,HIGH);
  }
  delay (8000);
  digitalWrite (rgb_Verde ,LOW);  //spengo i 2 led rgb
  digitalWrite (rgb_Rosso,LOW);
}
