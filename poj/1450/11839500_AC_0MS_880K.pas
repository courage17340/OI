var
  n,i,x,y:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(x,y);
      writeln('Scenario #',i,':');
      write(x*y);
      if odd(x*y) then writeln('.41') else writeln('.00');
      writeln;
    end;
end.