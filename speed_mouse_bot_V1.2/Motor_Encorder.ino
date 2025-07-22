void LMupdateEncoder()
{
if (digitalRead(LMEncoderPinA)> digitalRead(LMEncoderPinB))
LMEncodervalue++;
else
LMEncodervalue--;
}

void RMupdateEncoder()
{
if (digitalRead(RMEncoderPinA)> digitalRead(RMEncoderPinB))
RMEncodervalue++;
else
RMEncodervalue--;
}
