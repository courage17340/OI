var
  n,a,b,t,i:longint;
begin
  read(n);
  n:=n mod 49152;
  a:=1;b:=1;
  for i:=3 to n do
    begin
      t:=b;
      b:=(a+b) mod 32768;
      a:=t;
    end;
  writeln(b mod 32768);
end.