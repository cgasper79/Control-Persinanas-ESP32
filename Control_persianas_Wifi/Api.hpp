
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
    
}
