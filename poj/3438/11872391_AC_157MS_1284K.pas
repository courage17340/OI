var
  s,t,p:ansistring;
  n,i,j,k:longint;
begin
  readln(n);
  for k:=1 to n do
    begin
      readln(s);
      t:='';
      i:=1;
      j:=1;
      while i<=length(s) do
        begin
          while (j<length(s))and(s[j+1]=s[i]) do inc(j);
          str(j-i+1,p);
          t:=t+p+s[i];
          i:=j+1;
          j:=i;
        end;
      writeln(t);
    end;
end.