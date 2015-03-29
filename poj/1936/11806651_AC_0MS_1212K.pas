var
  s,t:ansistring;
  i,j:longint;
begin
  while not eof do
    begin
      readln(t);
      s:=copy(t,1,pos(' ',t)-1);
      delete(t,1,pos(' ',t));
      while t[1]=' ' do delete(t,1,1);
      i:=1;
      for j:=1 to length(t) do
        if t[j]=s[i] then
          begin
            inc(i);
            if i>length(s) then break;
          end;
      if i>length(s) then writeln('Yes') else writeln('No');
    end;
end.