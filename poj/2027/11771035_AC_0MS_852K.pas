var
  a,b,i,n:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(a,b);
      if a>=b then writeln('MMM BRAINS') else writeln('NO BRAINS');
    end;
end.