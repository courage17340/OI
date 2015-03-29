var
  n,m,p,c:longint;
begin
  while true do
    begin
      readln(n,m,p,c);
      if (n=m)and(m=p)and(p=c)and(c=0) then break;
      writeln(p-(m-n));
    end;
end.