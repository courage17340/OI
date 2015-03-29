var
  a,b:longint;
begin
  while not eof do
    begin
      readln(a,b);
      writeln(a mod b);
    end;
end.