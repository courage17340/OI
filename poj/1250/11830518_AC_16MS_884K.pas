var
  a:array['A'..'Z'] of longint;
  n,i,j,k,ans:longint;
  s:string;
function yes:boolean;
var
  j:longint;
  i:char;
begin
  j:=0;
  for i:='A' to 'Z' do
    if a[i]=1 then inc(j);
  exit(j<n);
end;
begin
  while true do
    begin
      ans:=0;
      read(n);
      if n=0 then break;
      readln(s);
      fillchar(a,sizeof(a),0);
      while s[1]=' ' do delete(s,1,1);
      for i:=1 to length(s) do
        case a[s[i]] of
          0:if yes then a[s[i]]:=1
                 else
                   begin
                     a[s[i]]:=2;
                     inc(ans);
                   end;
          1:a[s[i]]:=0;
        end;
      if ans=0
        then writeln('All customers tanned successfully.')
        else writeln(ans,' customer(s) walked away.');
    end;
end.