var
  x:extended;
  n:longint;
begin
  while not eof do
    begin
      readln(n,x);
      writeln(exp(ln(x)/n):0:0);
    end;
end.