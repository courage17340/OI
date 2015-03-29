var
  x,y:longint;
function num(x:longint):longint;
var i:longint;
begin
  num:=0;
  for i:=1 to x div 2 do num:=num+x div i;
  num:=num+x-x div 2;
end;
begin
  read(x,y);
  writeln(num(y)-num(x-1));
end.