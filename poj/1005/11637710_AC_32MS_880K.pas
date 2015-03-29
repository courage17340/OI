var
  x,y,s:double;
  n,i,j:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(x,y);
      s:=pi*(x*x+y*y)/2;
      writeln('Property ',i,': This property will begin eroding in year ',trunc(s/50)+1,'.');
    end;
  writeln('END OF OUTPUT.');
end.