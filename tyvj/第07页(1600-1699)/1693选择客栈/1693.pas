type rec=record colour,cost:longint;end;
var
  f:array[0..200000] of longint;
  b:array[0..50,0..200000] of longint;
  a:array[1..200000] of rec;
  n,i,j,k,p:longint;
  ans:int64;
function yes(i,j:longint):boolean;
begin
  if i>=j then exit(false);
  if f[i]>f[i-1] then exit(true);
  if f[j]>f[i] then exit(true);
  exit(false);
end;
begin
  readln(n,k,p);
  fillchar(a,sizeof(a),0);
  fillchar(f,sizeof(f),0);
  f[0]:=0;
  for i:=1 to n do
    begin
      f[i]:=f[i-1];
      readln(a[i].colour,a[i].cost);
      if a[i].cost<=p then inc(f[i]);
      inc(b[a[i].colour,0]);
      b[a[i].colour,b[a[i].colour,0]]:=i;
    end;
  ans:=0;
  for i:=0 to k-1 do
    begin
      k:=2;
      for j:=1 to b[i,0] do
        begin
          while (not yes(b[i,j],b[i,k]))and(k<b[i,0]) do inc(k);
          if yes(b[i,j],b[i,k]) then ans:=int64(ans+int64(b[i,0]-k+1));
        end;
    end;
  writeln(ans);
end.