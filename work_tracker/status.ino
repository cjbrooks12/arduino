void statusCommand(YunClient client) {
    int value = client.readStringUntil('\r').toInt();

    digitalWrite(ST_CP, LOW);
    shiftOut(DS, SH_CP, MSBFIRST, value);
    digitalWrite(ST_CP, HIGH);

    client.print("set status LEDs to ");
    client.print(value);
}
