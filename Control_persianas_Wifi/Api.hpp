
void doAction(String actionId)
{
   Serial.print("Doing action: ");
   Serial.println(actionId);

  if (actionId == "0")
   emisorSubir1();  
  
  if (actionId == "1")
   emisorBajar1(); 
  
  if (actionId == "2")
   emisorStop1();
    
  if (actionId == "3")
   emisorSubir2();

  if (actionId == "4")
   emisorBajar2();
    
  if (actionId == "5")
   emisorStop2();

  if (actionId == "6"){
   emisorSubir1();
   delay (200);
   emisorSubir2();
   }

   if (actionId == "7"){
   emisorBajar1();
   delay (200);
   emisorBajar2();
   }

   if (actionId == "8"){
   emisorStop1();
   delay (200);
   emisorStop2();
   }
    
}
