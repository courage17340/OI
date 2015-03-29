const max=22000;
var
  a,b,c,d,n,i:longint;
begin
  n:=0;
  while true do
    begin
      readln(a,b,c,d);
      if a=-1 then break;
      inc(n);
      for i:=d+1 to max do
        if ((i-a) mod 23=0)and((i-b) mod 28=0)and((i-c) mod 33=0) then break;
      writeln('Case ',n,': the next triple peak occurs in ',i-d,' days.');
    end;
end.