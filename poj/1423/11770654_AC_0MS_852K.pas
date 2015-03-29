var
  n,i,p:longint;
  x,e:extended;
begin
  readln(n);
  e:=2.718281828;
  for i:=1 to n do
    begin
      readln(p);
      x:=sqrt(2*pi*p);
      x:=ln(x)+p*ln(p/e);
      x:=x/ln(10);
      writeln(trunc(x)+1);
    end;
end.