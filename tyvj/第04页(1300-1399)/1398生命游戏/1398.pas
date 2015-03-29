var
  a:array[1..2,0..1001,0..1001] of 0..2;
  ch:char;
  i,j,m,n,t,a1,a2,p,q:longint;
function sum:longint;
begin
  sum:=0;
  if a[a1,i-1,j-1]=1 then inc(sum);
  if a[a1,i-1,j]=1 then inc(sum);
  if a[a1,i-1,j+1]=1 then inc(sum);
  if a[a1,i,j-1]=1 then inc(sum);
  if a[a1,i,j+1]=1 then inc(sum);
  if a[a1,i+1,j-1]=1 then inc(sum);
  if a[a1,i+1,j]=1 then inc(sum);
  if a[a1,i+1,j+1]=1 then inc(sum);
end;
begin
  fillchar(a,sizeof(a),2);
  readln(m,n,t);
  for i:=1 to n do
    begin
      for j:=1 to m do begin read(ch);a[1,i,j]:=ord(ch)-48;end;
      readln;
    end;
  a1:=1;a2:=2;
  for p:=1 to t do
    begin
      for i:=1 to n do
        for j:=1 to m do
          if a[a1,i,j]=0
            then if sum=3 then a[a2,i,j]:=1 else a[a2,i,j]:=0
            else if (sum<2)or(sum>3) then a[a2,i,j]:=0 else a[a2,i,j]:=1;
      q:=a1;a1:=a2;a2:=q;
    end;
  for i:=1 to n do
    begin
      for j:=1 to m do write(a[a2,i,j]);
      writeln;
    end;
end.