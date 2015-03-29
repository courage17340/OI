var
  a,b,c,n,i:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(a,b,c);
      if a<b-c then writeln('advertise');
      if a=b-c then writeln('does not matter');
      if a>b-c then writeln('do not advertise');
    end;
end.