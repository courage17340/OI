var
  ans,x,y:longint;
begin
  while not eof do
    begin
      readln(x);
      y:=1;
      ans:=1;
      while y<>0 do
        begin
          y:=y*10+1;
          y:=y mod x;
          inc(ans);
        end;
      writeln(ans);
    end;
end.