var
  a,b:longint;
begin
  while not eof do
    begin
      readln(a,b);
      if (b mod a=0)or(a*b=2) then writeln(1) else writeln(0);
    end;
end.
