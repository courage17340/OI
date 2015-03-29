var
  s,t:string;
  x:longint;
begin
  while not eof do
    begin
      readln(s);
      while true do
        begin
          readln(t);
          if t='END' then break;
          x:=pos(t,s);
          if (x=0)and(t<>'NULL') then
            begin
              writeln(length(s),' ',s);
              continue;
            end;
          if (x=1)or(t='NULL') then writeln('0 NULL') else writeln(x-1,' ',copy(s,1,x-1));
        end;
    end;
end.