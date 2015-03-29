var
  r,m,y,i:longint;
  x,s:extended;
begin
  readln(r,m,y);
  x:=1+r/100;
  s:=m;
  for i:=1 to y do
    s:=s*x;
  writeln(trunc(s));
end.