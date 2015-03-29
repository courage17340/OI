var
  x,y:extended;
begin
  readln(x);
  readln(y);
  while true do
    begin
      if trunc(y)=999 then break;
      writeln(y-x:0:2);
      x:=y;
      readln(y);
    end;
  writeln('End of Output');
end.