var
  x:longint;
function f(x:longint):string;
var
  i,s:longint;
begin
  s:=0;
  for i:=1 to x shr 1 do
    if x mod i=0 then inc(s,i);
  if x=s then exit('  PERFECT');
  if x<s then exit('  ABUNDANT');
  exit('  DEFICIENT');
end;
begin
  writeln('PERFECTION OUTPUT');
  while true do
    begin
      read(x);
      if x=0 then break;
      write(x:5);
      writeln(f(x));
    end;
  writeln('END OF OUTPUT');
end.