var
  n,i,j,x:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      j:=0;
      readln(x);
      while x>0 do
        begin
          x:=x div 5;
          inc(j,x);
        end;
      writeln(j);
    end;
end.