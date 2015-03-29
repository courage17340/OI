var
  n,x,y,i:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(x,y);
      if x<y
        then writeln('impossible')
        else writeln((x+y) shr 1,' ',(x-y) shr 1);
    end;
end.