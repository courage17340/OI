var
  m,t,u,f,d,time,i:longint;
  ch:char;
procedure print;
begin
  writeln(i-1);halt;
end;
begin
  readln(m,t,u,f,d);time:=0;
  for i:=1 to t do
    begin
      readln(ch);
      case ch of
        'u','d':time:=time+u+d;
        'f':time:=time+f+f;
        end;
      if time>m then print;
    end;
end.