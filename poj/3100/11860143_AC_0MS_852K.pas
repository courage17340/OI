var
  a,b,n:longint;
begin
  while true do
    begin
      readln(b,n);
      if b+n=0 then break;
      a:=trunc(exp(ln(b)/n));
      if abs(b-exp(n*ln(a)))>abs(exp(n*ln(a+1))-b) then inc(a);
      writeln(a);
    end;
end.