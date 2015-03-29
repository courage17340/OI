var
  k:longint;
  ch:char; 
begin
  k:=0;
  while not eof do
    begin
      read(ch);
      if ch in ['0'..'9'] then k:=k+ord(ch)-48;
    end;
  k:=k mod 3; 
  if k=0 then writeln('King will win.') else
    begin
      writeln('MaoLaoDa will win.'); 
      writeln(k); 
    end; 
  readln; 
end.