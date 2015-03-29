var
  s,t:ansistring;
  i,j:longint;
begin
  readln(i);
  while not eof do
    begin
      readln(t);
      s:=copy(t,1,pos(' ',t)-1);
      delete(t,1,pos(' ',t));
      while t[1]=' ' do delete(t,1,1);
      i:=1;
      for j:=1 to length(s) do
        if t[i]=s[j] then
          begin
            inc(i);
            if i>length(t) then break;
          end;
      if i>length(t) then writeln('YES') else
        begin
          i:=length(t);
          for j:=1 to length(s) do
            if t[i]=s[j] then
              begin
                dec(i);
                if i=0 then break;
              end;
          if i=0 then writeln('YES') else writeln('NO');
        end;
    end;
end.