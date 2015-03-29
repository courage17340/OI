var
  a:array[1..10100] of boolean;
  i:longint;
function f(x:longint):longint;
begin
  f:=x;
  while x>0 do
    begin
      f:=f+x mod 10;
      x:=x div 10;
    end;
end;
begin
  fillchar(a,sizeof(a),true);
  for i:=1 to 10000 do
    a[f(i)]:=false;
  for i:=1 to 10000 do
    if a[i] then writeln(i);
end.