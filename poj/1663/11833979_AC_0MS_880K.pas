var
  n,i,x,y:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(x,y);
      if (x<>y)and(x<>y+2) then
        begin
          writeln('No Number');
          continue;
        end;
      if x=y then
        if odd(x) then writeln(2*x-1)
                  else writeln(2*x);
      if x=y+2 then
        if odd(x) then writeln(2*x-3)
                  else writeln(2*x-2);
    end;
end.