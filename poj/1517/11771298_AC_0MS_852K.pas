var
  p,x:extended;
  n,i,j:longint;
begin
  writeln('n e');
  writeln('- -----------');
  writeln('0 1');
  writeln('1 2');
  writeln('2 2.5');
  x:=2.5;
  p:=0.5;
  for i:=3 to 9 do
    begin 
      p:=p/i;
      x:=x+p;
      writeln(i,' ',x:0:9);
    end;
end.