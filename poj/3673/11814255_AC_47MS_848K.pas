var
  a,b,x,y:longint;
begin
  readln(a,b);
  x:=0;
  while a>0 do
    begin
      inc(x,a mod 10);
      a:=a div 10;
    end;
  y:=0;
  while b>0 do
    begin
      inc(y,b mod 10);
      b:=b div 10;
    end;
  writeln(x*y);
end.