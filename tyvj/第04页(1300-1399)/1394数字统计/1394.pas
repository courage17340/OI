var
  L,R,i,j:longint;
function f(x:longint):longint;
var
  i:longint;
begin
  f:=0;
  while x>0 do
   begin
    i:=x mod 10;
    if i=2 then inc(f);
    x:=x div 10;
   end;
end;
begin
  readln(L,R);
  j:=0;
  for i:=L to R do j:=j+f(i);
  writeln(j);
end.