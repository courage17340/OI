var
  a,sum:array[0..1010] of longint;
  minf,maxf:array[0..2020,0..2020] of longint;
  n,i,j,maxans,minans,L,k,m:longint;
function max(a,b:longint):longint;
begin
  max:=a;
  if a<b then max:=b;
end;
function min(a,b:longint):longint;
begin
  min:=b;
  if a<b then if a>0 then min:=a;
end;
begin
  fillchar(sum,sizeof(sum),0);
  read(n,m);
  for i:=1 to n do begin read(a[i]);a[n+i]:=a[i];end;
  for i:=1 to 2*n do sum[i]:=sum[i-1]+a[i];
  fillchar(minf,sizeof(minf),200);
  fillchar(maxf,sizeof(maxf),0);
  for i:=1 to n*2 do minf[i,i]:=0;
  for L:=1 to n-1 do
    for i:=1 to 2*n-L do
      begin
        j:=i+L;
        for k:=i to j-1 do
          begin
            maxf[i,j]:=max(maxf[i,j],maxf[i,k]+maxf[k+1,j]);
            minf[i,j]:=min(minf[i,j],minf[i,k]+minf[k+1,j]);
          end;
        maxf[i,j]:=maxf[i,j]+sum[j]-sum[i-1];
        minf[i,j]:=minf[i,j]+sum[j]-sum[i-1];
      end;
  maxans:=-maxlongint;
  minans:=maxlongint;
  for i:=1 to n do maxans:=max(maxans,maxf[i,i+n-1]);
  for i:=1 to n do minans:=min(minans,minf[i,i+n-1]);
  if m>maxans then writeln('It is easy')
    else if m<minans then writeln('I am..Sha...X')
    else writeln('I will go to play WarIII');
end.