var
  f:array[0..100,0..100] of longint;
  n,m,i,j,x,y:longint;
begin
  fillchar(f,sizeof(f),0);
  for i:=0 to 100 do f[i,0]:=1;
  for i:=1 to 100 do
    for j:=1 to i do
      f[i,j]:=f[i-1,j]+f[i-1,j-1];
  while true do
    begin
      readln(x,y);
      if x=0 then break;
      writeln(x,' things taken ',y,' at a time is ',f[x,y],' exactly.');
    end;
end.