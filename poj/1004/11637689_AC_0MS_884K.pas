var
  x,y:double;
  i:longint;
begin
  y:=0;
  for i:=1 to 12 do
    begin
      readln(x); 
      y:=y+x;
    end;
  y:=y/12;
  writeln('$',y:0:2);
end.