var
  s:ansistring;
  j:longint;
begin
  while not eof do
    begin
      readln(s);
      while pos('you',s)>0 do
        begin
          j:=pos('you',s);
          s[j]:='w';
          s[j+1]:='e';
          delete(s,j+2,1);
        end;
      writeln(s);
    end;
end.