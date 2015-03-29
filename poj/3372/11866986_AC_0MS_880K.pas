var
  x:longint;
function f(x:longint):string;
begin
  while x and 1=0 do x:=x shr 1;
  if x<>1 then exit('NO');
  exit('YES');
end;
begin
  while not eof do
    begin
      readln(x);
      writeln(f(x));
    end;
end.