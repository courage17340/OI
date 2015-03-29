var
  a,b,x:extended;
  c,d:longint;
begin
  while true do
    begin
      readln(a,b,c,d);
      if c=0 then break;
      a:=a/(c*d);
      x:=(sqrt(a*a+4*a*b)-a)/2;
      x:=x*c;
      x:=-ln(x)/ln(10);
      writeln(x:0:3);
    end;
end.