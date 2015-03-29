var
  f:array[0..20,0..20,0..20] of longint;
  i,j,k,x,y,z:longint;
function g(x,y,z:longint):longint;
begin
  if (x>20)or(y>20)or(z>20) then exit(f[20,20,20]);
  if (x<=0)or(y<=0)or(z<=0) then exit(1);
  exit(f[x,y,z]);
end;
begin
  for i:=1 to 20 do
    for j:=1 to 20 do
      for k:=1 to 20 do
        if (i<j)and(j<k)
        then
          f[i,j,k]:=g(i,j,k-1)+g(i,j-1,k-1)-g(i,j-1,k)
        else
          f[i,j,k]:=g(i-1,j,k)+g(i-1,j-1,k)+g(i-1,j,k-1)-g(i-1,j-1,k-1);
  while true do
    begin
      readln(x,y,z);
      if (x=-1)and(y=-1)and(z=-1) then break;
      writeln('w(',x,', ',y,', ',z,') = ',g(x,y,z));
    end;
end.