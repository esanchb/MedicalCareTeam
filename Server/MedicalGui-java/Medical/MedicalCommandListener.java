package Medical;

import java.util.EventListener;

public abstract interface MedicalCommandListener
  extends EventListener
{
  public abstract void medicalCommandDataAvailable(CommandEvent paramCommandEvent);
}


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\MedicalCommandListener.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */