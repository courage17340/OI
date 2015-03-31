var
  x:int64;
begin
  readln(x);
  while x mod 3=0 do x:=x div 3;
  writeln(x div 3+1);
end.