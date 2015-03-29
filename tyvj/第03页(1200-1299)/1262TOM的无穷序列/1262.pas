var
  a,n,i:longint;
  x:real;
begin
  readln(n);
  for i:=1 to n do begin
  readln(a);
  x:=(0.5+sqrt(0.25+2*(a-1)));
  if x=trunc(x) then writeln(1) else writeln(0);
  end;
end.