var
  l,r,n:longint;
begin
  readln(n);
  l:=1;
  r:=n;
  while l<r do
    begin
      write(l,' ');
      inc(l);
      write(r,' ');
      dec(r);
    end;
  if l=r then writeln(l);
end.