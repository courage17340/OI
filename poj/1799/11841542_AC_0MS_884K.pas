var
  n,i,j,k:longint;
  r1,r2,x:extended;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(r1,j);
      x:=sin(pi/j);
      r2:=r1*x/(1+x);
      writeln('Scenario #',i,':');
      writeln(r2:0:3);
      writeln;
    end;
end.