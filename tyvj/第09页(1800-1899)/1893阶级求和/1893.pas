var
  n,k,i:longint;
  x,p:extended;
begin
  readln(k);
  x:=0;
  i:=0;
  while x<=k do
    begin
      inc(i);
      x:=x+1/i;
    end;
  writeln(i);
end.