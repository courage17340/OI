var
  m,n,k,t:longint;
begin
  m:=1;n:=1;
  read(k);
  while m+n<=k do
    begin
      t:=n;
      n:=m+n;
      m:=t;
    end;
  writeln(m,' ',n);
end.